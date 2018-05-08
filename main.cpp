/*
 * Copyright 2010-2015 Amazon.com, Inc. or its affiliates. All Rights Reserved.
 *
 * Licensed under the Apache License, Version 2.0 (the "License").
 * You may not use this file except in compliance with the License.
 * A copy of the License is located at
 *
 *  http://aws.amazon.com/apache2.0
 *
 * or in the "license" file accompanying this file. This file is distributed
 * on an "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either
 * express or implied. See the License for the specific language governing
 * permissions and limitations under the License.
 */

/**
 * @file subscribe_publish_cpp_sample.cpp
 * @brief simple MQTT publish and subscribe on the same topic in C++
 *
 * This example takes the parameters from the aws_iot_config.h file and establishes a connection to the AWS IoT MQTT Platform.
 * It subscribes and publishes to the same topic - "sdkTest/sub"
 *
 * If all the certs are correct, you should see the messages received by the application in a loop.
 *
 * The application takes in the certificate path, host name , port and the number of times the publish should happen.
 *
 */
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <unistd.h>
#include <limits.h>
#include <string.h>

#include "aws_iot_config.h"
#include "aws_iot_log.h"
#include "aws_iot_version.h"
#include "aws_iot_mqtt_client_interface.h"
#include "application_mqtt_aws.h"

#include <iostream>
using namespace std;

/**
 * @brief Default cert location
 */
char certDirectory[PATH_MAX + 1] = "../huydeptrai/aws-iot-device-sdk-c/certs";

/**
 * @brief Default MQTT HOST URL is pulled from the aws_iot_config.h
 */
char HostAddress[255] = AWS_IOT_MQTT_HOST;

/**
 * @brief Default MQTT port is pulled from the aws_iot_config.h
 */
uint32_t port = AWS_IOT_MQTT_PORT;

/**
 * @brief This parameter will avoid infinite loop of publish and exit the program after certain number of publishes
 */
uint32_t publishCount = 0;

void iot_subscribe_callback_handler(AWS_IoT_Client *pClient, char *topicName, uint16_t topicNameLen,
                                    IoT_Publish_Message_Params *params, void *pData) {
    IOT_UNUSED(pData);
    IOT_UNUSED(pClient);
    IOT_INFO("Subscribe callback");
//    IOT_INFO("%.*s\t%.*s", topicNameLen, topicName, (int) params->payloadLen, (char *) params->payload);

    char messages[(int)params->payloadLen];
    memset(messages, 0, (int)params->payloadLen);

    char topic_name[topicNameLen];
    for(int i = 0; i < topicNameLen; i++)
    {
        topic_name[i] = topicName[i];
    }

    cout << "New message\r\nTopic: " << topicName << endl;

    sprintf(messages, (char*)params->payload, (int)params->payloadLen);
    cout << messages << endl;
}

void disconnectCallbackHandler(AWS_IoT_Client *pClient, void *data) {
    // IOT_WARN("MQTT Disconnect");
    cout << "MQTT Disconnect" << endl;
    IoT_Error_t rc = FAILURE;

    if(NULL == pClient)
    {
        cout << "NULL pClient" << endl;
        return;
    }

    IOT_UNUSED(data);

    if(aws_iot_is_autoreconnect_enabled(pClient))
    {
        // IOT_INFO("Auto Reconnect is enabled, Reconnecting attempt will start now");
        cout << "Auto Reconnect is enabled, Reconnecting attempt will start now";
    }
    else
    {
        // IOT_WARN("Auto Reconnect not enabled. Starting manual reconnect...");
        cout << "Auto Reconnect not enabled. Starting manual reconnect..." << endl;
        rc = aws_iot_mqtt_attempt_reconnect(pClient);
        if(NETWORK_RECONNECTED == rc)
        {
            // IOT_WARN("Manual Reconnect Successful");
            cout << "Manual Reconnect Successful" << endl;
        }
        else
        {
            char error[128];
            sprintf(error, "Manual Reconnect Failed - %d", rc);
            // IOT_WARN("Manual Reconnect Failed - %d", rc);
            cout << error << endl;
        }
    }
}

void parseInputArgsForConnectParams(int argc, char **argv)
{
    int opt;

    while(-1 != (opt = getopt(argc, argv, "h:p:c:x:")))
    {
        switch(opt)
        {
            case 'h':
                strcpy(HostAddress, optarg);
                IOT_DEBUG("Host %s", optarg);
                break;
            case 'p':
                port = atoi(optarg);
                IOT_DEBUG("arg %s", optarg);
                break;
            case 'c':
                strcpy(certDirectory, optarg);
                IOT_DEBUG("cert root directory %s", optarg);
                break;
            case 'x':
                publishCount = atoi(optarg);
                IOT_DEBUG("publish %s times\n", optarg);
                break;
            case '?':
                if(optopt == 'c')
                {
                    IOT_ERROR("Option -%c requires an argument.", optopt);
                }
                else if(isprint(optopt))
                {
                    IOT_WARN("Unknown option `-%c'.", optopt);
                }
                else
                {
                    IOT_WARN("Unknown option character `\\x%x'.", optopt);
                }
                break;
            default:
                IOT_ERROR("Error in command line argument parsing");
                break;
        }
    }

}

char test_rootca_path[] = "/home/huy/huydeptrai/aws-iot-device-sdk-c/certs/rootCA.pem";
int test_rootca_path_len =  sizeof(test_rootca_path) / sizeof(char*);

string rootca_path = "/home/huy/huydeptrai/aws-iot-device-sdk-c/certs/rootCA.pem";
string client_crt_path = "/home/huy/huydeptrai/aws-iot-device-sdk-c/certs/cerforthings.crt";
string client_key = "/home/huy/huydeptrai/aws-iot-device-sdk-c/certs/private.key";
int main(int argc, char **argv)
{

    application_mqtt_aws test_broker(HostAddress, 8883, rootca_path, client_crt_path, client_key, NULL, true);
    test_broker.aws_mqtt_connect(600, AWS_IOT_MQTT_CLIENT_ID);
    test_broker.aws_mqtt_subscribe("sdkTest/clg", QOS0);
    test_broker.aws_mqtt_autoreconnect_eneable();

    aws_iot_mqtt_yield(&test_broker.aws_client, 1000000);
    test_broker.aws_mqtt_publish("testSdk/clg", "haha", QOS0);
    for(;;);

    bool infinitePublishFlag = true;
    char rootCA[PATH_MAX + 1];
    char clientCRT[PATH_MAX + 1];
    char clientKey[PATH_MAX + 1];
    char CurrentWD[PATH_MAX + 1];
    char cPayload[100];
    memset(rootCA, 0, PATH_MAX + 1);
    memset(clientCRT, 0, PATH_MAX + 1);
    memset(clientKey, 0, PATH_MAX + 1);

    int32_t i = 0;

    IoT_Error_t rc = FAILURE;

    AWS_IoT_Client client;
    IoT_Client_Init_Params mqttInitParams = iotClientInitParamsDefault;
    IoT_Client_Connect_Params connectParams = iotClientConnectParamsDefault;

    IoT_Publish_Message_Params paramsQOS0;

    parseInputArgsForConnectParams(argc, argv);

    char* aws_sdk_info = new char[512];
    sprintf(aws_sdk_info, "\r\nAWS IoT SDK Version %d.%d.%d-%s\r\n", VERSION_MAJOR, VERSION_MINOR, VERSION_PATCH, VERSION_TAG);
    // IOT_INFO("\nAWS IoT SDK Version %d.%d.%d-%s\n", VERSION_MAJOR, VERSION_MINOR, VERSION_PATCH, VERSION_TAG);
    cout << aws_sdk_info << endl;
    delete aws_sdk_info;

    getcwd(CurrentWD, sizeof(CurrentWD));
    snprintf(rootCA, PATH_MAX + 1, "%s/%s/%s", CurrentWD, certDirectory, AWS_IOT_ROOT_CA_FILENAME);
    snprintf(clientCRT, PATH_MAX + 1, "%s/%s/%s", CurrentWD, certDirectory, AWS_IOT_CERTIFICATE_FILENAME);
    snprintf(clientKey, PATH_MAX + 1, "%s/%s/%s", CurrentWD, certDirectory, AWS_IOT_PRIVATE_KEY_FILENAME);

    cout << "RootCA: " << rootCA << endl;
    cout << "ClientCRT: " << clientCRT << endl;
    cout << "ClientKey: " << clientKey << endl;

    mqttInitParams.enableAutoReconnect = false; // We enable this later below
    mqttInitParams.pHostURL = HostAddress;
    mqttInitParams.port = port;
    mqttInitParams.pRootCALocation = (char*)rootca_path.c_str();
    mqttInitParams.pDeviceCertLocation = (char*)client_crt_path.c_str();
    mqttInitParams.pDevicePrivateKeyLocation = (char*)client_key.c_str();
    mqttInitParams.mqttCommandTimeout_ms = 20000;
    mqttInitParams.tlsHandshakeTimeout_ms = 5000;
    mqttInitParams.isSSLHostnameVerify = true;
    mqttInitParams.disconnectHandler = disconnectCallbackHandler;
    mqttInitParams.disconnectHandlerData = NULL;

    rc = aws_iot_mqtt_init(&client, &mqttInitParams);
    if(SUCCESS != rc)
    {
    	char error[128];
    	sprintf(error, "aws_iot_mqtt_init error: %d", rc);
        //IOT_ERROR("aws_iot_mqtt_init returned error : %d ", rc);
        cout << error << endl;
        return rc;
    }
    else cout << "aws_iot_mqtt_init returned success" << endl;

    connectParams.keepAliveIntervalInSec = 600;
    connectParams.isCleanSession = true;
    connectParams.MQTTVersion = MQTT_3_1_1;
    connectParams.pClientID = (char *)AWS_IOT_MQTT_CLIENT_ID;
    connectParams.clientIDLen = (uint16_t) strlen(AWS_IOT_MQTT_CLIENT_ID);
    connectParams.isWillMsgPresent = false;

    // IOT_INFO("Connecting...");
    cout << "Connecting..." << endl;
    rc = aws_iot_mqtt_connect(&client, &connectParams);
    if(SUCCESS != rc)
    {
        char error[1024];
        sprintf(error, "Error (%d) connecting to %s:%d", rc, mqttInitParams.pHostURL, mqttInitParams.port);
         // IOT_ERROR("Error(%d) connecting to %s:%d", rc, mqttInitParams.pHostURL, mqttInitParams.port);
        cout << error << endl;
        return rc;
    }
    /*
     * Enable Auto Reconnect functionality. Minimum and Maximum time of Exponential backoff are set in aws_iot_config.h
     *  #AWS_IOT_MQTT_MIN_RECONNECT_WAIT_INTERVAL
     *  #AWS_IOT_MQTT_MAX_RECONNECT_WAIT_INTERVAL
     */
    rc = aws_iot_mqtt_autoreconnect_set_status(&client, true);
    if(SUCCESS != rc)
    {
        // IOT_ERROR("Unable to set Auto Reconnect to true - %d", rc);
        char error[128];
        sprintf(error, "Unable to set Auto Reconnect to true - %d", rc);
        cout << error << endl;
        return rc;
    }

    cout << "Subscribing..." << endl;
    rc = aws_iot_mqtt_subscribe(&client, "sdkTest/clg", 11, QOS0, iot_subscribe_callback_handler, NULL);

    if(SUCCESS != rc)
    {
        char error[64];
        sprintf(error, "%d", rc);
        cout << "Error subscribing, return error code" << rc << endl;
        return rc;
    }
    cout << "Subscribing return success" << endl;

    sprintf(cPayload, "%s : %d ", "hello from SDK", i);

    paramsQOS0.qos = QOS0;
    paramsQOS0.payload = (void *) cPayload;
    paramsQOS0.isRetained = 0;


    if(publishCount != 0)
    {
        infinitePublishFlag = false;
    }

    while((NETWORK_ATTEMPTING_RECONNECT == rc || NETWORK_RECONNECTED == rc || SUCCESS == rc)
          && (publishCount > 0 || infinitePublishFlag))
    {

        //Max time the yield function will wait for read messages
        rc = aws_iot_mqtt_yield(&client, 100);
        if(NETWORK_ATTEMPTING_RECONNECT == rc)
        {
            // If the client is attempting to reconnect we will skip the rest of the loop.
            continue;
        }
        sprintf(cPayload, "%s : %d ", "hello from SDK QOS0", i++);
        cout << "Publishing topic sdkTest/sub, payload:" << cPayload << endl;
        paramsQOS0.payloadLen = strlen(cPayload);
        rc = aws_iot_mqtt_publish(&client, "sdkTest/sub", 11, &paramsQOS0);
        if(publishCount > 0)
        {
            publishCount--;
        }

        sleep(5);
    }

    if(SUCCESS != rc)
    {
        // IOT_ERROR("An error occurred in the loop.\n");
        cout << "An error occurred in the loop" << endl;
    }
    else
    {
        // IOT_INFO("Publish done\r\n");
        cout << "Publish done" << endl;
    }

    return rc;
}
