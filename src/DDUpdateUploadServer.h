#ifndef __DDUPDATEUPLOADSERVERSERVER_H
#define __DDUPDATEUPLOADSERVERSERVER_H

#include <FS.h>
#include <Arduino.h>
#include <WiFiClient.h>
#include <WiFiServer.h>
#include <ESP8266WebServer.h>
#include <WiFiUdp.h>
#include <StreamString.h>
#define emptyString String()

#define USE_HTML_MIN_GZ

// class ESP8266WebServer;

class DDUpdateUploadServer
{
  public:
    DDUpdateUploadServer(bool serial_debug=true, const fs::FS& fs = SPIFFS);

    void setup(ESP8266WebServer *server)
    {
      setup(server, emptyString, emptyString);
    }

    void setup(ESP8266WebServer *server, const String& path)
    {
      setup(server, path, emptyString, emptyString);
    }

    void setup(ESP8266WebServer *server, const String& username, const String& password)
    {
      setup(server, "/update", username, password);
    }

    void setup(ESP8266WebServer *server, const String& path, const String& username, const String& password);

    void updateCredentials(const String& username, const String& password)
    {
      _username = username;
      _password = password;
    }

  protected:
    void _setUpdaterError();

  private:
    fs::FS _fs;
    bool _serial_output;
    ESP8266WebServer *_server;
    String _username;
    String _password;
    bool _authenticated;
    String _updaterError;
    File fsUploadFile;
};


#endif
