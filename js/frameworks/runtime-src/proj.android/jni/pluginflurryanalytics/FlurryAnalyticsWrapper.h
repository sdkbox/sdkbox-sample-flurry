
#ifndef __PLUGIN_FLURRY_ANALYTICS_WRAPPER_H__
#define __PLUGIN_FLURRY_ANALYTICS_WRAPPER_H__


#include "PluginFlurryAnalytics.h"
#include "CocosMacros.h"
#include "json98.h"

#define TAG             "FlurryAnalytics"
#define VERSION         "7.1.1"
#define IOS_VERSION     "ios: 7.6.6"
#define ANDROID_VERSION "android: 6.0.0"

NS_COCOS_BEGIN

class FlurryAnalyticsWrapper {
public:

    static FlurryAnalyticsWrapper* getInstance();

    virtual void setListener(FlurryAnalyticsListener *listener)=0;
    virtual FlurryAnalyticsListener* getListener()=0;
    virtual void removeListener()=0;
    virtual bool init()=0;
    virtual void setAppVersion(const std::string& version)=0;
    virtual std::string getFlurryAgentVersion()=0;
    virtual void setShowErrorInLogEnabled(bool value)=0;
    virtual void setDebugLogEnabled(bool value)=0;
    virtual void setLogLevel(FA_FlurryLogLevel value)=0;
    virtual void setSessionContinueSeconds(float seconds)=0;
    virtual void setCrashReportingEnabled(bool value)=0;
    virtual void startSession()=0;
    virtual void endSession()=0;
    virtual bool activeSessionExists()=0;
    virtual std::string getSessionID()=0;
    virtual void pauseBackgroundSession()=0;
    virtual void addOrigin(const std::string& originName, const std::string& originVersion)=0;
    virtual void addOrigin(const std::string& originName, const std::string& originVersion, std::map<std::string, std::string>& parameters)=0;
    virtual void addOrigin(const std::string& originName, const std::string& originVersion, const std::string& parameters)=0;
    virtual int logEvent(const std::string& eventName)=0;
    virtual int logEvent(const std::string& eventName, std::map<std::string, std::string>& parameters)=0;
    virtual int logEvent(const std::string& eventName, const std::string& parameters)=0;
    virtual int logEvent(const std::string& eventName, bool timed)=0;
    virtual int logEvent(const std::string& eventName, std::map<std::string, std::string>& parameters, bool timed)=0;
    virtual int logEvent(const std::string& eventName, const std::string& parameters, bool timed)=0;
    virtual void endTimedEvent(const std::string& eventId)=0;
    virtual void endTimedEvent(const std::string& eventName, std::map<std::string, std::string>& parameters)=0;
    virtual void endTimedEvent(const std::string& eventName, const std::string& parameters)=0;
    virtual void logError(const std::string& errorID, const std::string& message, const std::string& info)=0;
    virtual void logPageView()=0;
    virtual void setUserID(const std::string& userID)=0;
    virtual void setAge(int age)=0;
    virtual void setGender(const std::string& gender)=0;	// user's gender m or f
    virtual void setReportLocation(bool reportLocation)=0;
    virtual void setLatitude(double latitude, double longitude, float horizontalAccuracy, float verticalAccuracy)=0;
    virtual void clearLocation()=0;
    virtual void setSessionReportsOnCloseEnabled(bool sendSessionReportsOnClose)=0;
    virtual void setSessionReportsOnPauseEnabled(bool setSessionReportsOnPauseEnabled)=0;
    virtual void setBackgroundSessionEnabled(bool setBackgroundSessionEnabled)=0;
    virtual void setEventLoggingEnabled(bool value)=0;
    virtual void setPulseEnabled(bool value)=0;
};

class FlurryAnalyticsWrapperDisabled : public FlurryAnalyticsWrapper {
public:
    void setListener(FlurryAnalyticsListener *listener) {}
    FlurryAnalyticsListener* getListener() { return NULL; }
    void removeListener() {}
    bool init() { return false; }
    void setAppVersion(const std::string& version) {}
    std::string getFlurryAgentVersion() { return ""; }
    void setShowErrorInLogEnabled(bool value) {}
    void setDebugLogEnabled(bool value) {}
    void setLogLevel(FA_FlurryLogLevel value) {}
    void setSessionContinueSeconds(float seconds) {}
    void setCrashReportingEnabled(bool value) {}
    void startSession() {}
    void endSession() {}
    bool activeSessionExists() { return false; }
    std::string getSessionID() { return ""; }
    void pauseBackgroundSession() {}
    void addOrigin(const std::string& originName, const std::string& originVersion) {}
    void addOrigin(const std::string& originName, const std::string& originVersion, std::map<std::string, std::string>& parameters) {}
    void addOrigin(const std::string& originName, const std::string& originVersion, const std::string& parameters) {}
    int logEvent(const std::string& eventName) { return -1; }
    int logEvent(const std::string& eventName, std::map<std::string, std::string>& parameters) { return -1; }
    int logEvent(const std::string& eventName, const std::string& parameters) { return -1; }
    int logEvent(const std::string& eventName, bool timed) { return -1; }
    int logEvent(const std::string& eventName, std::map<std::string, std::string>& parameters, bool timed) { return -1; }
    int logEvent(const std::string& eventName, const std::string& parameters, bool timed) { return -1; }
    void endTimedEvent(const std::string& eventId) {}
    void endTimedEvent(const std::string& eventName, std::map<std::string, std::string>& parameters) {}
    void endTimedEvent(const std::string& eventName, const std::string& parameters) {}
    void logError(const std::string& errorID, const std::string& message, const std::string& info) {}
    void logPageView() {}
    void setUserID(const std::string& userID) {}
    void setAge(int age) {}
    void setGender(const std::string& gender) {}
    void setReportLocation(bool reportLocation) {}
    void setLatitude(double latitude, double longitude, float horizontalAccuracy, float verticalAccuracy) {}
    void clearLocation() {}
    void setSessionReportsOnCloseEnabled(bool sendSessionReportsOnClose) {}
    void setSessionReportsOnPauseEnabled(bool setSessionReportsOnPauseEnabled) {}
    void setBackgroundSessionEnabled(bool setBackgroundSessionEnabled) {}
    void setEventLoggingEnabled(bool value) {}
    void setPulseEnabled(bool value) {}
};


class FlurryAnalyticsWrapperEnabled : public FlurryAnalyticsWrapper {
public:
    FlurryAnalyticsWrapperEnabled();
    void setListener(FlurryAnalyticsListener *listener);
    FlurryAnalyticsListener* getListener();
    void removeListener();
    bool init();
    void setAppVersion(const std::string& version);
    std::string getFlurryAgentVersion();
    void setShowErrorInLogEnabled(bool value);
    void setDebugLogEnabled(bool value);
    void setLogLevel(FA_FlurryLogLevel value);
    void setSessionContinueSeconds(float seconds);
    void setCrashReportingEnabled(bool value);
    void startSession();
    void endSession();
    bool activeSessionExists();
    std::string getSessionID();
    void pauseBackgroundSession();
    void addOrigin(const std::string& originName, const std::string& originVersion);
    void addOrigin(const std::string& originName, const std::string& originVersion, std::map<std::string, std::string>& parameters);
    void addOrigin(const std::string& originName, const std::string& originVersion, const std::string& parameters);
    int logEvent(const std::string& eventName);
    int logEvent(const std::string& eventName, std::map<std::string, std::string>& parameters);
    int logEvent(const std::string& eventName, const std::string& parameters);
    int logEvent(const std::string& eventName, bool timed);
    int logEvent(const std::string& eventName, std::map<std::string, std::string>& parameters, bool timed);
    int logEvent(const std::string& eventName, const std::string& parameters, bool timed);
    void endTimedEvent(const std::string& eventId);
    void endTimedEvent(const std::string& eventName, std::map<std::string, std::string>& parameters);
    void endTimedEvent(const std::string& eventName, const std::string& parameters);
    void logError(const std::string& errorID, const std::string& message, const std::string& info);
    void logPageView();
    void setUserID(const std::string& userID);
    void setAge(int age);
    void setGender(const std::string& gender);	// user's gender m or f
    void setReportLocation(bool reportLocation);
    void setLatitude(double latitude, double longitude, float horizontalAccuracy, float verticalAccuracy);
    void clearLocation();
    void setSessionReportsOnCloseEnabled(bool sendSessionReportsOnClose);
    void setSessionReportsOnPauseEnabled(bool setSessionReportsOnPauseEnabled);
    void setBackgroundSessionEnabled(bool setBackgroundSessionEnabled);
    void setEventLoggingEnabled(bool value);
    void setPulseEnabled(bool value);

protected:
    bool nativeConfigure(Json& config);
    const char* nativeSDKVersion();
    bool _init;
    FlurryAnalyticsListener* _listener;
    std::string _apiKey;
};


NS_COCOS_END

#endif
