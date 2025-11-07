//
//  EWMicroInverterProfiles.h
//  EWBluetoothDemo
//
//  Created by developer on 2023/5/29.
//

#ifndef EWMicroInverterProfiles_h
#define EWMicroInverterProfiles_h

#import <EWBluetoothSDK/EWBluetoothSDK.h>

typedef NS_ENUM(NSUInteger, EWMICommandType) {
    EWMICommandTypeStart = 22,          // 启动
    EWMICommandTypeStop = 33,          // 停止
    EWMICommandTypeNetwork = 0x03,      // 配置网络
};

typedef NS_ENUM(NSUInteger, EWMIWiFiStatus) {
    EWMIWiFiStatusDisconnect = 0x00,     // 未连接
    EWMIWiFiStatusConnecting = 0x01,     // 连接中
    EWMIWiFiStatusConnected = 0x02,      // 已连接
    EWMIWiFiStatusConnectFailed = 0x03,  // 连接失败
    EWMIWiFiStatusDisabled = 0x04,       // 不可用
    EWMIWiFiStatusUnknow = 0x99,         // 未知
};

// 蓝牙状态回调
typedef void (^EWBluetoothDidUpdateStateHandler)(EWBluetoothState state);
// 发现微逆回调(蓝牙广播号)
typedef void (^EWScanMicroInverterHandler)(NSString *_Nullable microInverterName);
// 微逆消失回调(蓝牙广播号)
typedef void (^EWMicroInverterDisappearHandler)(NSString *_Nullable microInverterName);
// 停止扫描微逆回调(是否成功)
typedef void (^EWStopScanMicroInverterHandler)(BOOL success);
// 获取微逆 Wi-Fi 状态(名称，Wi-Fi 状态，错误信息)
typedef void (^EWMicroInverterWiFiStatusHandler)(NSString * _Nullable microInverterName, EWMIWiFiStatus status, NSError * _Nullable error);
// 获取微逆Wi-Fi信息(名称，Wi-Fi，错误信息)
typedef void (^EWMicroInverterWiFiInformationHandler)(NSString * _Nullable microInverterName, NSString * _Nullable wifiName,  NSError * _Nullable error);
// 获取手机Wi-Fi(名称，Mac，数据)
typedef void (^EWWifiInformationHandler)(NSString * _Nullable wifiName, NSString * _Nullable mac, NSData * _Nullable data, NSError * _Nullable error);
// 微逆成功失败结果回调(名称，成功否，错误)
typedef void (^EWMicroInverterResultHandler)(NSString * _Nullable microInverterName, BOOL result, NSError * _Nullable error);

#endif /* EWMicroInverterProfiles_h */
