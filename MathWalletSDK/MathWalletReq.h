//
//  MathWalletReq.h
//  MathWalletSDK
//
//  Created by Yuzhiyou on 2018/9/26.
//  Copyright © 2018年 Math Wallet. All rights reserved.
//

#import <Foundation/Foundation.h>
/*!
 * @class MathWalletReq
 * @brief 基础数据
 */
@interface MathWalletReq : NSObject

@property (nonatomic, readonly) NSString *protocol;           // 协议名，钱包用来区分不同协议，本协议为 SimpleWallet
@property (nonatomic, readonly) NSString *version;            // 协议版本信息，如1.0
@property (nonatomic, copy) NSString *dappName;               // dapp名字，用于在钱包APP中展示
@property (nonatomic, copy) NSString *dappIcon;               // dapp图标Url，用于在钱包APP中展示
@property (nonatomic, copy) NSString *blockchain;             // 公链标识（eosio、ont、ethereum等）
@property (nonatomic, copy) NSString *action;                 // 登录时，赋值为login。支付时，赋值为transfer;

// Req->NSDictionary
-(NSDictionary *)toParams;
@end

#pragma mark - 登录
/*!
 * @class MathWalletLoginReq
 * @brief 登录附加数据
 */
@interface MathWalletLoginReq : MathWalletReq

@property (nonatomic, copy) NSString *uuID;                     // dapp生成的，用于dapp登录验证唯一标识
@property (nonatomic, copy) NSString *loginUrl;                 // dapp server生成的，用于接受此次登录验证的URL
@property (nonatomic, copy) NSNumber *expired;                  // 登录过期时间，unix时间戳
@property (nonatomic, copy) NSString *loginMemo;                // 登录备注信息，钱包用来展示

@end

#pragma mark - 转账
/*!
 * @class MathWalletTransferReq
 * @brief 转账附加数据
 */
@interface MathWalletTransferReq : MathWalletReq

@property (nonatomic, copy) NSString *from;                     // 付款人的账户或地址
@property (nonatomic, copy) NSString *to;                       // 收款人的账户或地址
@property (nonatomic, copy) NSString *amount;                   // 转账数量。如果精度为4、转账数量为1，则为1.0000；
@property (nonatomic, copy) NSString *contract;                 // 转账的token所属的contract账号名或地址
@property (nonatomic, copy) NSString *symbol;                   // 转账的token symbol
@property (nonatomic, copy) NSNumber *precision;                // 转账的token的精度，小数点后面的位数
@property (nonatomic, copy) NSString *dappData;                 // 由dapp生成的业务参数信息，需要钱包在转账时附加在memo或data中发出去

@property (nonatomic, copy) NSString *desc;                     // 交易的说明信息，钱包在付款UI展示给用户，最长不要超过128个字节
@property (nonatomic, copy) NSNumber *expired;                  // 交易过期时间，unix时间戳

@end
