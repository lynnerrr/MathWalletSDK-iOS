//
//  MathWalletResp.h
//  MathWalletSDK
//
//  Created by Yuzhiyou on 2018/9/26.
//  Copyright © 2018年 Math Wallet. All rights reserved.
//

#import <Foundation/Foundation.h>
/*!
 * @brief 处理结果
 */
typedef NS_ENUM(NSUInteger, MathWalletRespResult) {
    MathWalletRespResultCanceled = 0,               // 取消
    MathWalletRespResultSuccess,                    // 成功
    MathWalletRespResultFailure,                    // 失败
};

/*!
 * @brief   响应回调
 * @discuss data    action=transfer -> data={"txID":"交易ID"}
 *                  action=login -> data=nil
 */

@interface MathWalletResp : NSObject
@property (nonatomic, assign) MathWalletRespResult result;      // 处理结果
@property (nonatomic, copy) NSString *action;      // 处理类型
@property (nonatomic, copy) NSDictionary *data;                 // 附加数据
@end
