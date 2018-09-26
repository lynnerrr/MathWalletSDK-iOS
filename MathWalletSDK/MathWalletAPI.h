//
//  MathWalletAPI.h
//  MathWalletSDK
//
//  Created by Yuzhiyou on 2018/9/26.
//  Copyright © 2018年 Math Wallet. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "MathWalletReq.h"
#import "MathWalletResp.h"
/*!
 * @class MathWalletAPI
 */
@interface MathWalletAPI : NSObject

/*!
 * @brief 注册URL Schemes
 * @param urlSchemes 在Xcode工程info.plist-> URL types -> URL Schemes里添加
 */
+ (void)registerAppURLSchemes:(NSString *)urlSchemes;

/*!
 * @brief 向 MathWallet 发起请求
 * @param req 登录/转账
 * @return YES/NO
 */
+ (BOOL)sendReq:(MathWalletReq *)req;

/*!
 * @brief   处理MathWallet的回调
 * @discuss 在AppDelegate -(application:openURL:options:)方法里调用
 */
+ (BOOL)handleURL:(NSURL *)url result:(void(^)(MathWalletResp *resq))result;

@end
