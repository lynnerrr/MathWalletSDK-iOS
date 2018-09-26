# MathWalletSDK-iOS
基于SimpleWallet 协议的SDK



## 如何使用？

### 1、在Xcode工程info.plist-> URL types -> URL Schemes里添加
![URL Schemes](https://github.com/MediShares/MathWalletSDK-iOS/blob/master/urlschemes.jpeg "URL Schemes")


### 2、注册URL Schemes和处理URL

```Objective C
#import <MathWalletSDK/MathWalletAPI.h>
  
  
@implementation AppDelegate


- (BOOL)application:(UIApplication *)application didFinishLaunchingWithOptions:(NSDictionary *)launchOptions {
    // Override point for customization after application launch.
    [MathWalletAPI registerAppURLSchemes:@"mathwalletdemos"];
    return YES;
}


-(BOOL)application:(UIApplication *)app openURL:(NSURL *)url options:(NSDictionary<UIApplicationOpenURLOptionsKey,id> *)options{
    BOOL handle = [MathWalletAPI handleURL:url result:^(MathWalletResp *resq) {
        NSLog(@"%@",resq.data);
    }];
    return handle;
}
@end
```

### 3、跳转到MathWallet进行登录操作

```Objective C
  MathWalletLoginReq *loginReq = [[MathWalletLoginReq alloc] init];
  // 公链标识
  loginReq.blockchain = @"eosio";
  // DApp信息
  loginReq.dappIcon = @"http://www.mathwallet.org/images/download/wallet_cn.png";
  loginReq.dappName = @"Demos";
  // DApp Server
  loginReq.uuID = @"本次登录uid";
  loginReq.loginUrl = @"登录回调";
  loginReq.expired = [NSNumber numberWithLong:[NSDate date].timeIntervalSince1970];
  loginReq.loginMemo = @"Memo";


  [MathWalletAPI sendReq:loginReq];
@end
```
