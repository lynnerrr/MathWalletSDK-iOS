# MathWalletSDK-iOS
基于SimpleWallet 协议的SDK



##如何使用？

###1、在Xcode工程info.plist-> URL types -> URL Schemes里添加
![URL Schemes](https://github.com/MediShares/MathWalletSDK-iOS/blob/master/urlschemes.jpeg "URL Schemes")


###2、使用MathWalletAPI注册URL Schemes 和 处理URL，代码如下
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
