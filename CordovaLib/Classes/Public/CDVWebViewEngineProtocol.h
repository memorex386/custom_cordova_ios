/*
 Licensed to the Apache Software Foundation (ASF) under one
 or more contributor license agreements.  See the NOTICE file
 distributed with this work for additional information
 regarding copyright ownership.  The ASF licenses this file
 to you under the Apache License, Version 2.0 (the
 "License"); you may not use this file except in compliance
 with the License.  You may obtain a copy of the License at

 http://www.apache.org/licenses/LICENSE-2.0

 Unless required by applicable law or agreed to in writing,
 software distributed under the License is distributed on an
 "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY
 KIND, either express or implied.  See the License for the
 specific language governing permissions and limitations
 under the License.
 */

#import <UIKit/UIKit.h>
#import <WebKit/WebKit.h>

#define kCDVWebViewEngineScriptMessageHandlers @"kCDVWebViewEngineScriptMessageHandlers"
#define kCDVWebViewEngineUIWebViewDelegate @"kCDVWebViewEngineUIWebViewDelegate"
#define kCDVWebViewEngineWKNavigationDelegate @"kCDVWebViewEngineWKNavigationDelegate"
#define kCDVWebViewEngineWKUIDelegate @"kCDVWebViewEngineWKUIDelegate"
#define kCDVWebViewEngineWebViewPreferences @"kCDVWebViewEngineWebViewPreferences"

@protocol CDVWebViewEngineProtocol <NSObject>

@property (nonatomic, strong, readonly) UIView* engineWebView;
@property (nonatomic, copy) BOOL (^completionHandler)(WKUserContentController* userContentController, WKScriptMessage* message);

- (id)loadRequest:(NSURLRequest*)request;
- (id)loadHTMLString:(NSString*)string baseURL:(NSURL*)baseURL;
- (void)evaluateJavaScript:(NSString*)javaScriptString completionHandler:(void (^)(id, NSError*))completionHandler;

- (NSURL*)URL;
- (BOOL)canLoadRequest:(NSURLRequest*)request;

- (instancetype)initWithFrame:(CGRect)frame;
- (void)updateWithInfo:(NSDictionary*)info;
    
- (void)handleContent:(BOOL (^)(WKUserContentController*, WKScriptMessage*))completionHandler;

-(NSURLRequest*)checkUrlLoadRequest:(NSURLRequest*)request;
@end
