#-------------------------------------------------
#
# Project created by QtCreator 2018-05-05T10:08:33
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = huydeptrai
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS \
           BOCORODO_DEBUG

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += \
        main.cpp \
        mainwindow.cpp \
    aws-iot-device-sdk-c/external_libs/jsmn/jsmn.c \
    aws-iot-device-sdk-c/external_libs/mbedTLS/library/aes.c \
    aws-iot-device-sdk-c/external_libs/mbedTLS/library/aesni.c \
    aws-iot-device-sdk-c/external_libs/mbedTLS/library/arc4.c \
    aws-iot-device-sdk-c/external_libs/mbedTLS/library/asn1parse.c \
    aws-iot-device-sdk-c/external_libs/mbedTLS/library/asn1write.c \
    aws-iot-device-sdk-c/external_libs/mbedTLS/library/base64.c \
    aws-iot-device-sdk-c/external_libs/mbedTLS/library/bignum.c \
    aws-iot-device-sdk-c/external_libs/mbedTLS/library/blowfish.c \
    aws-iot-device-sdk-c/external_libs/mbedTLS/library/camellia.c \
    aws-iot-device-sdk-c/external_libs/mbedTLS/library/ccm.c \
    aws-iot-device-sdk-c/external_libs/mbedTLS/library/certs.c \
    aws-iot-device-sdk-c/external_libs/mbedTLS/library/cipher.c \
    aws-iot-device-sdk-c/external_libs/mbedTLS/library/cipher_wrap.c \
    aws-iot-device-sdk-c/external_libs/mbedTLS/library/cmac.c \
    aws-iot-device-sdk-c/external_libs/mbedTLS/library/ctr_drbg.c \
    aws-iot-device-sdk-c/external_libs/mbedTLS/library/debug.c \
    aws-iot-device-sdk-c/external_libs/mbedTLS/library/des.c \
    aws-iot-device-sdk-c/external_libs/mbedTLS/library/dhm.c \
    aws-iot-device-sdk-c/external_libs/mbedTLS/library/ecdh.c \
    aws-iot-device-sdk-c/external_libs/mbedTLS/library/ecdsa.c \
    aws-iot-device-sdk-c/external_libs/mbedTLS/library/ecjpake.c \
    aws-iot-device-sdk-c/external_libs/mbedTLS/library/ecp.c \
    aws-iot-device-sdk-c/external_libs/mbedTLS/library/ecp_curves.c \
    aws-iot-device-sdk-c/external_libs/mbedTLS/library/entropy.c \
    aws-iot-device-sdk-c/external_libs/mbedTLS/library/entropy_poll.c \
    aws-iot-device-sdk-c/external_libs/mbedTLS/library/error.c \
    aws-iot-device-sdk-c/external_libs/mbedTLS/library/gcm.c \
    aws-iot-device-sdk-c/external_libs/mbedTLS/library/havege.c \
    aws-iot-device-sdk-c/external_libs/mbedTLS/library/hmac_drbg.c \
    aws-iot-device-sdk-c/external_libs/mbedTLS/library/md.c \
    aws-iot-device-sdk-c/external_libs/mbedTLS/library/md2.c \
    aws-iot-device-sdk-c/external_libs/mbedTLS/library/md4.c \
    aws-iot-device-sdk-c/external_libs/mbedTLS/library/md5.c \
    aws-iot-device-sdk-c/external_libs/mbedTLS/library/md_wrap.c \
    aws-iot-device-sdk-c/external_libs/mbedTLS/library/memory_buffer_alloc.c \
    aws-iot-device-sdk-c/external_libs/mbedTLS/library/net_sockets.c \
    aws-iot-device-sdk-c/external_libs/mbedTLS/library/oid.c \
    aws-iot-device-sdk-c/external_libs/mbedTLS/library/padlock.c \
    aws-iot-device-sdk-c/external_libs/mbedTLS/library/pem.c \
    aws-iot-device-sdk-c/external_libs/mbedTLS/library/pk.c \
    aws-iot-device-sdk-c/external_libs/mbedTLS/library/pk_wrap.c \
    aws-iot-device-sdk-c/external_libs/mbedTLS/library/pkcs11.c \
    aws-iot-device-sdk-c/external_libs/mbedTLS/library/pkcs12.c \
    aws-iot-device-sdk-c/external_libs/mbedTLS/library/pkcs5.c \
    aws-iot-device-sdk-c/external_libs/mbedTLS/library/pkparse.c \
    aws-iot-device-sdk-c/external_libs/mbedTLS/library/pkwrite.c \
    aws-iot-device-sdk-c/external_libs/mbedTLS/library/platform.c \
    aws-iot-device-sdk-c/external_libs/mbedTLS/library/ripemd160.c \
    aws-iot-device-sdk-c/external_libs/mbedTLS/library/rsa.c \
    aws-iot-device-sdk-c/external_libs/mbedTLS/library/rsa_internal.c \
    aws-iot-device-sdk-c/external_libs/mbedTLS/library/sha1.c \
    aws-iot-device-sdk-c/external_libs/mbedTLS/library/sha256.c \
    aws-iot-device-sdk-c/external_libs/mbedTLS/library/sha512.c \
    aws-iot-device-sdk-c/external_libs/mbedTLS/library/ssl_cache.c \
    aws-iot-device-sdk-c/external_libs/mbedTLS/library/ssl_ciphersuites.c \
    aws-iot-device-sdk-c/external_libs/mbedTLS/library/ssl_cli.c \
    aws-iot-device-sdk-c/external_libs/mbedTLS/library/ssl_cookie.c \
    aws-iot-device-sdk-c/external_libs/mbedTLS/library/ssl_srv.c \
    aws-iot-device-sdk-c/external_libs/mbedTLS/library/ssl_ticket.c \
    aws-iot-device-sdk-c/external_libs/mbedTLS/library/ssl_tls.c \
    aws-iot-device-sdk-c/external_libs/mbedTLS/library/threading.c \
    aws-iot-device-sdk-c/external_libs/mbedTLS/library/timing.c \
    aws-iot-device-sdk-c/external_libs/mbedTLS/library/version.c \
    aws-iot-device-sdk-c/external_libs/mbedTLS/library/version_features.c \
    aws-iot-device-sdk-c/external_libs/mbedTLS/library/x509.c \
    aws-iot-device-sdk-c/external_libs/mbedTLS/library/x509_create.c \
    aws-iot-device-sdk-c/external_libs/mbedTLS/library/x509_crl.c \
    aws-iot-device-sdk-c/external_libs/mbedTLS/library/x509_crt.c \
    aws-iot-device-sdk-c/external_libs/mbedTLS/library/x509_csr.c \
    aws-iot-device-sdk-c/external_libs/mbedTLS/library/x509write_crt.c \
    aws-iot-device-sdk-c/external_libs/mbedTLS/library/x509write_csr.c \
    aws-iot-device-sdk-c/external_libs/mbedTLS/library/xtea.c \
    aws-iot-device-sdk-c/platform/linux/common/timer.c \
    aws-iot-device-sdk-c/platform/linux/mbedtls/network_mbedtls_wrapper.c \
    aws-iot-device-sdk-c/platform/linux/pthread/threads_pthread_wrapper.c \
    aws-iot-device-sdk-c/src/aws_iot_jobs_interface.c \
    aws-iot-device-sdk-c/src/aws_iot_jobs_json.c \
    aws-iot-device-sdk-c/src/aws_iot_jobs_topics.c \
    aws-iot-device-sdk-c/src/aws_iot_jobs_types.c \
    aws-iot-device-sdk-c/src/aws_iot_json_utils.c \
    aws-iot-device-sdk-c/src/aws_iot_mqtt_client.c \
    aws-iot-device-sdk-c/src/aws_iot_mqtt_client_common_internal.c \
    aws-iot-device-sdk-c/src/aws_iot_mqtt_client_connect.c \
    aws-iot-device-sdk-c/src/aws_iot_mqtt_client_publish.c \
    aws-iot-device-sdk-c/src/aws_iot_mqtt_client_subscribe.c \
    aws-iot-device-sdk-c/src/aws_iot_mqtt_client_unsubscribe.c \
    aws-iot-device-sdk-c/src/aws_iot_mqtt_client_yield.c \
    aws-iot-device-sdk-c/src/aws_iot_shadow.c \
    aws-iot-device-sdk-c/src/aws_iot_shadow_actions.c \
    aws-iot-device-sdk-c/src/aws_iot_shadow_json.c \
    aws-iot-device-sdk-c/src/aws_iot_shadow_records.c \
    application_mqtt_aws/application_mqtt_aws.cpp

HEADERS += \
        mainwindow.h \
    aws-iot-device-sdk-c/external_libs/jsmn/jsmn.h \
    aws-iot-device-sdk-c/external_libs/mbedTLS/configs/config-ccm-psk-tls1_2.h \
    aws-iot-device-sdk-c/external_libs/mbedTLS/configs/config-mini-tls1_1.h \
    aws-iot-device-sdk-c/external_libs/mbedTLS/configs/config-no-entropy.h \
    aws-iot-device-sdk-c/external_libs/mbedTLS/configs/config-suite-b.h \
    aws-iot-device-sdk-c/external_libs/mbedTLS/configs/config-thread.h \
    aws-iot-device-sdk-c/external_libs/mbedTLS/include/mbedtls/aes.h \
    aws-iot-device-sdk-c/external_libs/mbedTLS/include/mbedtls/aesni.h \
    aws-iot-device-sdk-c/external_libs/mbedTLS/include/mbedtls/arc4.h \
    aws-iot-device-sdk-c/external_libs/mbedTLS/include/mbedtls/asn1.h \
    aws-iot-device-sdk-c/external_libs/mbedTLS/include/mbedtls/asn1write.h \
    aws-iot-device-sdk-c/external_libs/mbedTLS/include/mbedtls/base64.h \
    aws-iot-device-sdk-c/external_libs/mbedTLS/include/mbedtls/bignum.h \
    aws-iot-device-sdk-c/external_libs/mbedTLS/include/mbedtls/blowfish.h \
    aws-iot-device-sdk-c/external_libs/mbedTLS/include/mbedtls/bn_mul.h \
    aws-iot-device-sdk-c/external_libs/mbedTLS/include/mbedtls/camellia.h \
    aws-iot-device-sdk-c/external_libs/mbedTLS/include/mbedtls/ccm.h \
    aws-iot-device-sdk-c/external_libs/mbedTLS/include/mbedtls/certs.h \
    aws-iot-device-sdk-c/external_libs/mbedTLS/include/mbedtls/check_config.h \
    aws-iot-device-sdk-c/external_libs/mbedTLS/include/mbedtls/cipher.h \
    aws-iot-device-sdk-c/external_libs/mbedTLS/include/mbedtls/cipher_internal.h \
    aws-iot-device-sdk-c/external_libs/mbedTLS/include/mbedtls/cmac.h \
    aws-iot-device-sdk-c/external_libs/mbedTLS/include/mbedtls/compat-1.3.h \
    aws-iot-device-sdk-c/external_libs/mbedTLS/include/mbedtls/config.h \
    aws-iot-device-sdk-c/external_libs/mbedTLS/include/mbedtls/ctr_drbg.h \
    aws-iot-device-sdk-c/external_libs/mbedTLS/include/mbedtls/debug.h \
    aws-iot-device-sdk-c/external_libs/mbedTLS/include/mbedtls/des.h \
    aws-iot-device-sdk-c/external_libs/mbedTLS/include/mbedtls/dhm.h \
    aws-iot-device-sdk-c/external_libs/mbedTLS/include/mbedtls/ecdh.h \
    aws-iot-device-sdk-c/external_libs/mbedTLS/include/mbedtls/ecdsa.h \
    aws-iot-device-sdk-c/external_libs/mbedTLS/include/mbedtls/ecjpake.h \
    aws-iot-device-sdk-c/external_libs/mbedTLS/include/mbedtls/ecp.h \
    aws-iot-device-sdk-c/external_libs/mbedTLS/include/mbedtls/ecp_internal.h \
    aws-iot-device-sdk-c/external_libs/mbedTLS/include/mbedtls/entropy.h \
    aws-iot-device-sdk-c/external_libs/mbedTLS/include/mbedtls/entropy_poll.h \
    aws-iot-device-sdk-c/external_libs/mbedTLS/include/mbedtls/error.h \
    aws-iot-device-sdk-c/external_libs/mbedTLS/include/mbedtls/gcm.h \
    aws-iot-device-sdk-c/external_libs/mbedTLS/include/mbedtls/havege.h \
    aws-iot-device-sdk-c/external_libs/mbedTLS/include/mbedtls/hmac_drbg.h \
    aws-iot-device-sdk-c/external_libs/mbedTLS/include/mbedtls/md.h \
    aws-iot-device-sdk-c/external_libs/mbedTLS/include/mbedtls/md2.h \
    aws-iot-device-sdk-c/external_libs/mbedTLS/include/mbedtls/md4.h \
    aws-iot-device-sdk-c/external_libs/mbedTLS/include/mbedtls/md5.h \
    aws-iot-device-sdk-c/external_libs/mbedTLS/include/mbedtls/md_internal.h \
    aws-iot-device-sdk-c/external_libs/mbedTLS/include/mbedtls/memory_buffer_alloc.h \
    aws-iot-device-sdk-c/external_libs/mbedTLS/include/mbedtls/net.h \
    aws-iot-device-sdk-c/external_libs/mbedTLS/include/mbedtls/net_sockets.h \
    aws-iot-device-sdk-c/external_libs/mbedTLS/include/mbedtls/oid.h \
    aws-iot-device-sdk-c/external_libs/mbedTLS/include/mbedtls/padlock.h \
    aws-iot-device-sdk-c/external_libs/mbedTLS/include/mbedtls/pem.h \
    aws-iot-device-sdk-c/external_libs/mbedTLS/include/mbedtls/pk.h \
    aws-iot-device-sdk-c/external_libs/mbedTLS/include/mbedtls/pk_internal.h \
    aws-iot-device-sdk-c/external_libs/mbedTLS/include/mbedtls/pkcs11.h \
    aws-iot-device-sdk-c/external_libs/mbedTLS/include/mbedtls/pkcs12.h \
    aws-iot-device-sdk-c/external_libs/mbedTLS/include/mbedtls/pkcs5.h \
    aws-iot-device-sdk-c/external_libs/mbedTLS/include/mbedtls/platform.h \
    aws-iot-device-sdk-c/external_libs/mbedTLS/include/mbedtls/platform_time.h \
    aws-iot-device-sdk-c/external_libs/mbedTLS/include/mbedtls/ripemd160.h \
    aws-iot-device-sdk-c/external_libs/mbedTLS/include/mbedtls/rsa.h \
    aws-iot-device-sdk-c/external_libs/mbedTLS/include/mbedtls/rsa_internal.h \
    aws-iot-device-sdk-c/external_libs/mbedTLS/include/mbedtls/sha1.h \
    aws-iot-device-sdk-c/external_libs/mbedTLS/include/mbedtls/sha256.h \
    aws-iot-device-sdk-c/external_libs/mbedTLS/include/mbedtls/sha512.h \
    aws-iot-device-sdk-c/external_libs/mbedTLS/include/mbedtls/ssl.h \
    aws-iot-device-sdk-c/external_libs/mbedTLS/include/mbedtls/ssl_cache.h \
    aws-iot-device-sdk-c/external_libs/mbedTLS/include/mbedtls/ssl_ciphersuites.h \
    aws-iot-device-sdk-c/external_libs/mbedTLS/include/mbedtls/ssl_cookie.h \
    aws-iot-device-sdk-c/external_libs/mbedTLS/include/mbedtls/ssl_internal.h \
    aws-iot-device-sdk-c/external_libs/mbedTLS/include/mbedtls/ssl_ticket.h \
    aws-iot-device-sdk-c/external_libs/mbedTLS/include/mbedtls/threading.h \
    aws-iot-device-sdk-c/external_libs/mbedTLS/include/mbedtls/timing.h \
    aws-iot-device-sdk-c/external_libs/mbedTLS/include/mbedtls/version.h \
    aws-iot-device-sdk-c/external_libs/mbedTLS/include/mbedtls/x509.h \
    aws-iot-device-sdk-c/external_libs/mbedTLS/include/mbedtls/x509_crl.h \
    aws-iot-device-sdk-c/external_libs/mbedTLS/include/mbedtls/x509_crt.h \
    aws-iot-device-sdk-c/external_libs/mbedTLS/include/mbedtls/x509_csr.h \
    aws-iot-device-sdk-c/external_libs/mbedTLS/include/mbedtls/xtea.h \
    aws-iot-device-sdk-c/include/aws_iot_error.h \
    aws-iot-device-sdk-c/include/aws_iot_jobs_interface.h \
    aws-iot-device-sdk-c/include/aws_iot_jobs_json.h \
    aws-iot-device-sdk-c/include/aws_iot_jobs_topics.h \
    aws-iot-device-sdk-c/include/aws_iot_jobs_types.h \
    aws-iot-device-sdk-c/include/aws_iot_json_utils.h \
    aws-iot-device-sdk-c/include/aws_iot_log.h \
    aws-iot-device-sdk-c/include/aws_iot_mqtt_client.h \
    aws-iot-device-sdk-c/include/aws_iot_mqtt_client_common_internal.h \
    aws-iot-device-sdk-c/include/aws_iot_mqtt_client_interface.h \
    aws-iot-device-sdk-c/include/aws_iot_shadow_actions.h \
    aws-iot-device-sdk-c/include/aws_iot_shadow_interface.h \
    aws-iot-device-sdk-c/include/aws_iot_shadow_json.h \
    aws-iot-device-sdk-c/include/aws_iot_shadow_json_data.h \
    aws-iot-device-sdk-c/include/aws_iot_shadow_key.h \
    aws-iot-device-sdk-c/include/aws_iot_shadow_records.h \
    aws-iot-device-sdk-c/include/aws_iot_version.h \
    aws-iot-device-sdk-c/include/network_interface.h \
    aws-iot-device-sdk-c/include/threads_interface.h \
    aws-iot-device-sdk-c/include/timer_interface.h \
    aws-iot-device-sdk-c/platform/linux/common/timer_platform.h \
    aws-iot-device-sdk-c/platform/linux/mbedtls/network_platform.h \
    aws-iot-device-sdk-c/platform/linux/pthread/threads_platform.h \
    aws-iot-device-sdk-c/samples/linux/subscribe_publish_cpp_sample/aws_iot_config.h \
    application_mqtt_aws/application_mqtt_aws.h

FORMS += \
        mainwindow.ui

DISTFILES += \
    aws-iot-device-sdk-c/certs/README.txt

INCLUDEPATH += $$PWD/aws-iot-device-sdk-c/external_libs/mbedTLS/include/ \
               $$PWD/aws-iot-device-sdk-c/include \
               $$PWD/aws-iot-device-sdk-c/platform/linux/common \
               $$PWD/aws-iot-device-sdk-c/platform/linux/mbedtls \
               $$PWD/aws-iot-device-sdk-c/external_libs/jsmn \
               $$PWD/aws-iot-device-sdk-c/samples/linux/subscribe_publish_cpp_sample/ \
               $$PWD/application_mqtt_aws

