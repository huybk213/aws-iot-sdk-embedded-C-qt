#include "application_mqtt_aws.h"

static void aws_mqtt_subscribe_callback_handler(AWS_IoT_Client *pClient, char *topicName,
                                                 uint16_t topicNameLen, IoT_Publish_Message_Params *params,
                                                 void *pData)         /* New message callback handler */
{
#ifdef BOCORODO_DEBUG
    cout << "New message" << endl;
#endif
}
application_mqtt_aws::application_mqtt_aws(string host_url, unsigned int port, string root_ca_path, string client_crt_path,
                                           string client_key_path, iot_disconnect_handler disconnect_callback, bool auto_reconnect)
{
    this->host_url = host_url;
    this->port = port;
    this->root_ca = root_ca_path;
    this->client_crt = client_crt_path;
    this->client_key = client_key_path;
    this->auto_reconnect = auto_reconnect;
    this->mqttInitParams.disconnectHandler = disconnect_callback;


    mqttInitParams.enableAutoReconnect = this->auto_reconnect;
    mqttInitParams.pHostURL = (char*) (this->host_url).c_str();
    mqttInitParams.port = this->port;
    mqttInitParams.pRootCALocation = (char*) (this->root_ca).c_str();
    mqttInitParams.pDeviceCertLocation = (char*) (this->client_crt).c_str();
    mqttInitParams.pDevicePrivateKeyLocation = (char*) (this->client_key).c_str();
    mqttInitParams.mqttCommandTimeout_ms = 20000;
    mqttInitParams.tlsHandshakeTimeout_ms = 5000;
    mqttInitParams.isSSLHostnameVerify = true;
    mqttInitParams.disconnectHandler = disconnect_callback;
    mqttInitParams.disconnectHandlerData = NULL;


#ifdef BOCORODO_DEBUG
    char* messages_info =  new char[4096];
    sprintf(messages_info, "\r\nAWS IoT SDK Version %d.%d.%d-%s\r\n", VERSION_MAJOR, VERSION_MINOR, VERSION_PATCH, VERSION_TAG);
    cout << messages_info << endl;
    sprintf(messages_info, "Host url: %s, port: %d, auto reconnect = %d", this->mqttInitParams.pHostURL, this->port, this->auto_reconnect);
    cout << messages_info << endl;
    cout << "RootCA location: " << this->root_ca << endl;
    cout << "Client certificate location: " << this->client_crt << endl;
    cout << "Client key location: " << this->client_key << endl;
    cout << "mqttCommandTimeout_ms: " << 20000 << endl;
    cout << "tlsHandshakeTimeout_ms: " << 5000 << endl;
    cout << "isSSLHostnameVerify: true" << endl;
#endif
    this->aws_mqtt_init();
    delete messages_info;


}

void application_mqtt_aws::aws_mqtt_init()
{
    IoT_Error_t rc = FAILURE;
    rc = aws_iot_mqtt_init(& this->aws_client, &this->mqttInitParams);
    if(SUCCESS != rc)
    {
#ifdef BOCORODO_DEBUG
        cout << "aws init error" << endl;
        return;
#endif
    }
    else
    {
#ifdef BOCORODO_DEBUG
        cout << "aws init success" << endl;
#endif
        return;
    }
}

/* Connect to server */
void application_mqtt_aws::aws_mqtt_connect(int keep_alive_second, string mqtt_client_id)
{


    this->aws_mqtt_client_id = mqtt_client_id;
    this->keepAliveIntervalInSec = keep_alive_second;
    this->connectParams.keepAliveIntervalInSec = this->keepAliveIntervalInSec;
    this->connectParams.isCleanSession = true;
    this->connectParams.MQTTVersion = MQTT_3_1_1;
    this->connectParams.pClientID = (char *)(this->aws_mqtt_client_id).c_str();
    this->connectParams.clientIDLen = (uint16_t) (this->aws_mqtt_client_id.length());
    this->connectParams.isWillMsgPresent = false;

#ifdef BOCORODO_DEBUG
       cout << "Connecting..." << endl;
#endif

    IoT_Error_t rc = FAILURE;
    rc = aws_iot_mqtt_connect(&this->aws_client, &this->connectParams);
    if(SUCCESS != rc)
    {
        char* error = new char[1024];
        sprintf(error, "Error (%d) connecting to %s:%d", rc, mqttInitParams.pHostURL, mqttInitParams.port);
        cout << error << endl;
        delete error;
        return;
    }
#ifdef BOCORODO_DEBUG
    char* error = new char[1024];
    sprintf(error, "Connected to %s:%d", mqttInitParams.pHostURL, mqttInitParams.port);
    cout << error << endl;
    delete error;
    return;
#endif
}


/* Subscribe topic */
void application_mqtt_aws::aws_mqtt_subscribe(string topic, QoS qos)
{
    this->subscribe_topic =  topic;
#ifdef BOCORODO_DEBUG
    cout << "Subscribing topic: " << topic << endl;
#endif
    IoT_Error_t rc = FAILURE;
    rc = aws_iot_mqtt_subscribe(&this->aws_client, (const char*)topic.c_str(), (uint16_t)this->subscribe_topic.length(),
                                qos, aws_mqtt_subscribe_callback_handler, NULL);
    if(SUCCESS != rc)
    {
         char error[64];
         sprintf(error, "%d", rc);
         cout << "Error subscribing, return error code" << rc << endl;
         return;
    }
    else  cout << "Subscribing return success" << endl;

}

void application_mqtt_aws::aws_mqtt_publish(string topic, string payload, QoS qos)
{
#ifdef BOCORODO_DEBUG
    cout << "Publishing" << endl;
#endif

    IoT_Error_t rc;
    this->publish_topic = topic;
    this->paramsQOSx.qos = qos;
    this->paramsQOSx.payload = (void*) payload.c_str();
    this->paramsQOSx.payloadLen = payload.length();
    this->paramsQOSx.isRetained = 0;
    rc = aws_iot_mqtt_publish(&this->aws_client, (const char*) topic.c_str(), topic.length(), &this->paramsQOSx);
    if(SUCCESS != rc)
    {
#ifdef BOCORODO_DEBUG
        cout << "Publish message error to topic " << topic << endl;
#endif
        return;
    }
    else
    {
#ifndef BOCORODO_DEBUG
        cout << "Publish message to topic " << topic.c_str() << " successful" << endl;
#endif
    }
}


/* Auto reconnect funtion */
void application_mqtt_aws::aws_mqtt_autoreconnect_eneable()
{
    IoT_Error_t rc;
    rc = aws_iot_mqtt_autoreconnect_set_status(&this->aws_client, true);
    if(SUCCESS != rc)
    {
#ifdef BOCORODO_DEBUG
        char error[128];
        sprintf(error, "Unable to set Auto Reconnect to true - %d", rc);
        cout << error << endl;
#endif
        return;
    }
    else
    {
#ifdef BOCORODO_DEBUG
        cout << "Set auto reconnect successful with AWS_IOT_MQTT_MIN_RECONNECT_WAIT_INTERVAL = " << AWS_IOT_MQTT_MIN_RECONNECT_WAIT_INTERVAL;
        cout << ", AWS_IOT_MQTT_MAX_RECONNECT_WAIT_INTERVAL = " << AWS_IOT_MQTT_MAX_RECONNECT_WAIT_INTERVAL << endl;
        cout << "AWS_IOT_MIX[MAX]_RECONNECT_WAIT_INTERVAL define in file aws_iot_config.h" << endl;
#endif
    }
}

/* Publish topic */
void aws_iot_publish(string topic);



/* Disconnect callback hanlder */
//void application_mqtt_aws::iot_disconnect_callback_handler(AWS_IoT_Client *pClient, void *data)
//{

//}

void application_mqtt_aws::iot_disconnect_callback_handler()
{

}

/* Parse arguments for main */
void application_mqtt_aws::parseInputArgsForConnectParams(int argc, char **argv)
{

}
