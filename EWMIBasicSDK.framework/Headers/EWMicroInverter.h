//
//  EWMicroInverter.h
//  EWBluetoothDemo
//
//  Created by developer on 2023/5/29.
//
#import <EWBluetoothSDK/EWBluetoothSDK.h>
#import <Foundation/Foundation.h>
#import "EWMicroInverterProfiles.h"

NS_ASSUME_NONNULL_BEGIN

@interface EWMicroInverter : NSObject
/// 蓝牙状态发生变化
@property (nonatomic, copy) EWBluetoothDidUpdateStateHandler bluetoothDidUpdateStateHandler;

///单例
+ (instancetype)share;

///配置搜索配置
- (void)ew_configMicroInverterScanWithName: (NSString *)filterName;

/// 扫描附近的微逆
/// - Parameter handler: 扫描回调
- (void)ew_scanMicroInverterHandler:(EWScanMicroInverterHandler)handler;

/// 附近的微逆消失，消失后无法连接，请同步删除保存的微逆
/// - Parameter handler: 扫描回调
- (void)ew_microInverterDisappearHandler:(EWMicroInverterDisappearHandler)handler;

/// 停止扫描附近的微逆
/// - Parameter handler: 成功回调
- (void)ew_stopScanMicroInverterHandler:(EWStopScanMicroInverterHandler)handler;

/// 启动微逆模块
/// - Parameters:
///   - microInverterName: 微逆蓝牙广播号
///   - handler: 启动是否成功回调
- (void)startMicroInverterModule:(NSString *)microInverterName
                        handler:(EWMicroInverterResultHandler)handler;

/// 关闭微逆模块
/// - Parameter microInverterName: 微逆蓝牙广播号
- (void)ew_stopMicroInverterModule:(NSString *)microInverterName;

/// 微逆断开，包含被动及主动断开
/// - Parameter handler: 断开回调
- (void)ew_microInverterDisconnectedHandler:(EWMicroInverterResultHandler)handler;

/// 获取微逆 Wi-Fi 状态
/// - Parameters:
///   - microInverterName: 微逆蓝牙广播号
///   - handler: 获取微逆 Wi-Fi 状态回调
- (void)ew_getMicroInverterWiFiStatus:(NSString *)microInverterName
                             handler:(EWMicroInverterWiFiStatusHandler)handler;

/// 给微逆传输 Wi-Fi 信息
/// - Parameters:
///   - microInverterName: 微逆蓝牙广播号
///   - SSID: Wi-Fi名称
///   - password: Wi-Fi密码
///   - handler: 获取微逆 Wi-Fi 状态回调
- (void)ew_transmitWiFiInformationToMicroInverter:(NSString *)microInverterName
                                            SSID:(NSString *)SSID
                                        password:(nullable NSString *)password
                                         handler:(EWMicroInverterWiFiStatusHandler)handler;

/// 微逆连接 Wi-Fi
/// - Parameters:
///   - microInverterName: 微逆蓝牙广播号
///   - handler: 获取微逆 Wi-Fi 状态回调
- (void)ew_microInverterConnectionWiFi:(NSString *)microInverterName
                              handler:(EWMicroInverterWiFiStatusHandler)handler;

/// 断开微逆 Wi-Fi
/// - Parameters:
///   - microInverterName: 微逆蓝牙广播号
///   - handler: 获取微逆 Wi-Fi 状态回调
- (void)ew_disconnectMicroInverterWiFi:(NSString *)microInverterName
                              handler:(EWMicroInverterWiFiStatusHandler)handler;

/// 获取微逆Wi-Fi信息
/// - Parameters:
///   - microInverterName: 微逆蓝牙广播号
///   -  handler: 获取微逆 Wi-Fi 信息回调
- (void)ew_getMicroInverterWiFiInformation:(NSString *)microInverterName
                                  handler:(EWMicroInverterWiFiInformationHandler)handler;

/// 重置微逆 Wi-Fi
/// - Parameters:
///   - microInverterName: 微逆蓝牙广播号
///   -  handler: 重置回调
- (void)ew_resetMicroInverterWiFi:(NSString *)microInverterName
                         handler:(EWMicroInverterResultHandler)handler;


/// 获取是否在线
/// - Parameters:
///   - microInverterName: 微逆蓝牙广播号
///   - handler: 回调
- (void)ew_getOnlineStatus:(NSString *)microInverterName
                                 handler:(EWMicroInverterResultHandler)handler;
@end

NS_ASSUME_NONNULL_END
