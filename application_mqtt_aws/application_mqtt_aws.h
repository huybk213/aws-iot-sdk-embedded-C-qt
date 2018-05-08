/*
 * Author: HuyTV
 */

#ifndef APPLICATION_MQTT_AWS_H
#define APPLICATION_MQTT_AWS_H

#include <iostream>
#include <string>

/* AWS SDK Includes file */
#include "aws_iot_config.h"
#include "aws_iot_log.h"                                /* For debug */
#include "aws_iot_version.h"
#include "aws_iot_mqtt_client_interface.h"

//char certDirectory[PATH_MAX + 1] = "../../../certs";    /* Default certificate location */
//char HostAddress[255] = AWS_IOT_MQTT_HOST;              /* Default MQTT HOST URL is pulled from the aws_iot_config.h */
//uint32_t port = AWS_IOT_MQTT_PORT;                      /* Default MQTT port is pulled from the aws_iot_config.h */

using namespace std;

#define HOST_URL_MAX_SIZE 255

static void aws_mqtt_subscribe_callback_handler(AWS_IoT_Client *pClient, char *topicName,
                                                 uint16_t topicNameLen, IoT_Publish_Message_Params *params,
                                                 void *pData);         /* New message callback handler */
class application_mqtt_aws
{
private:
    uint32_t aws_mqtt_port;
    uint32_t aws_host_address;
    string host_url;
    string aws_certificate_directory;
    string root_ca;                 /* AWS RootCA certificate path + file name, ex /home/certs/rootCA.pem */
    string client_crt;               /* AWS client certificate path + file name*/
    string client_key;              /* AWS client key path + file name */
    unsigned int port;
    char current_wd[PATH_MAX + 1];
    IoT_Error_t rc = FAILURE;                   /* AWS default error code */
    IoT_Client_Init_Params mqttInitParams = iotClientInitParamsDefault;      /* MQTT init default parameter */
    IoT_Client_Connect_Params connectParams = iotClientConnectParamsDefault; /* MQTT connect default parameter */
    IoT_Publish_Message_Params paramsQOSx;
    bool auto_reconnect = false;
    int keepAliveIntervalInSec;       /* Default value */
    string aws_mqtt_client_id;
    string subscribe_topic;
    string publish_topic;

private:

    void aws_mqtt_init();     /* Init parameter for mqtt */

public:
    AWS_IoT_Client aws_client;
    application_mqtt_aws(string host_url, unsigned int port, string root_ca_path, string client_crt_path,
                         string client_key_path, iot_disconnect_handler disconnect_callback, bool auto_reconnect);
    ~application_mqtt_aws() {}

    void aws_mqtt_connect(int keep_alive_second, string mqtt_client_id);
    void aws_mqtt_subscribe(string topic, QoS qos);
    void aws_iot_publish(string topic);


//    void iot_disconnect_callback_handler(AWS_IoT_Client *pClient, void *data);                                           /* Disconnect callback hanlder */
    void iot_disconnect_callback_handler();                                           /* Disconnect callback hanlder */
    void parseInputArgsForConnectParams(int argc, char **argv);                                                          /* Parse arguments for main */

};

#endif // APPLICATION_MQTT_AWS_H
