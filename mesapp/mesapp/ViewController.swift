//
//  ViewController.swift
//  mesapp
//
//  Created by MR.NOBODY on 17/2/3.
//  Copyright © 2017年 MR.WANG. All rights reserved.
//

import UIKit
import WebKit

import JavaScriptCore

//@objc  protocol  exitJsDelegate:JSExport{
//    func exitJs()
//}
//
//@objc class exitJsModel:NSObject,exitJsDelegate{
//    var jsContext:JSContext!
//    func  exitJs() {
//        
//    print("exec quit!!*********")
//        
//    exit(0)
//     
//    }
//}


//class ViewController: UIViewController ,UIWebViewDelegate {
class ViewController: UIViewController {
    var wkWebView: WKWebView?
    var uiWebView: UIWebView?
   
    
    override func viewDidLoad() {
        super.viewDidLoad()
        // Do any additional setup after loading the view, typically from a nib.
        
        // Get main screen rect size
        let screenSize: CGRect = UIScreen.main.bounds
        
        // Construct frame where webview will be pop
        let frameRect: CGRect = CGRect(x: 0, y: 0, width: screenSize.width, height: screenSize.height)
        
        // Create url request from local index.html file located in web_content
        //let url: URL = Bundle.main.url(forResource: "web_content/index", withExtension: "html")!
        
        // Create a url request that points to a remote server (uncomment this line to use a remote url)
        // let url: NSURL = NSURL(string: "http://example.com")!;
        
        
        
        //-----------------------------------------------------
        // 获取 token,用户名,密码,ECID 以及 ESN
        let  tokenStr  = MobileArkAgent.getToken();
        //        let  tokenTemp     =  "{\"resultcode\":\"0\",\"resultmessage\":\"success\",\"secrettoken\":\"AAEPQVBQU1RPUkVfQ2xpZW50RlABbBH_oL5fPy6vj7kGIyOJ588V3kgZFyrTik31XvIJc7eKQyd6GmnB1_MXrg3z6PrVE8znyshwfeYir-Syzon5BDD6cR5e-fdOrckYUQ0\"}";
        //        let  resultCode:String?
        //        let  tokentimeout:String?
        //        let  secrettoken:String?
        
        let testData = tokenStr?.data(using: String.Encoding.utf8, allowLossyConversion: false)
        
        
        
        let  temp:Any = try! JSONSerialization.jsonObject(with: testData!, options: JSONSerialization.ReadingOptions.mutableContainers)
        let jsonDic = temp as!Dictionary<String,Any>
        
        //let resultCode = jsonDic["resultcode"];
        let secrettoken = jsonDic["secrettoken"];
        
        let  loginnamepara = "loginname";
        //       let  passwordparam = "password";
        //       let  esnparam       = "esn";
        let  loginname  = MobileArkAgent.getParam(loginnamepara);
        //        let  password   = MobileArkAgent.getParam(passwordparam);
        //        let  esn        = MobileArkAgent.getParam(esnparam);
        //-------------------------------------------------------------------------------
        

        let url: NSURL = NSURL(string: urlstr)!;
        
        let requestObj: URLRequest = URLRequest(url: url as URL);
        
        // Test operating system
        if ProcessInfo().isOperatingSystemAtLeast(OperatingSystemVersion(majorVersion: 8, minorVersion: 0, patchVersion: 0)) {
            
            self.wkWebView = WKWebView(frame: frameRect)
            self.wkWebView?.load(requestObj)
            
            self.view.addSubview(self.wkWebView!)
            
        } else {
            
            self.uiWebView = UIWebView(frame: frameRect)
            self.uiWebView?.loadRequest(requestObj)
            self.view.addSubview(self.uiWebView!)
        }
        
        
    }
    
    override func didReceiveMemoryWarning() {
        super.didReceiveMemoryWarning()
        // Dispose of any resources that can be recreated.
    }
    
    //Commented:    black status bar.
    //Uncommented:  white status bar.
    override var preferredStatusBarStyle : UIStatusBarStyle {
        return UIStatusBarStyle.lightContent
    }
    
//    func webViewDidFinishLoad(_ webView: UIWebView) {
//        self.jsContext = webView.value(forKeyPath: "documentView。webView.mainFrame.javaScriptContext") as! JSContext
//        let model = exitJsModel()
//        
//        model.jsContext = self.jsContext
//        // 将 exitJS 以对象的形式，注入到js 中
//        self.jsContext.setObject(model, forKeyedSubscript: "exitJsUtil" as (NSCopying & NSObjectProtocol)!)
//        
//        
//        let  curUrl =  webView.request?.url?.absoluteString
//        self.jsContext.evaluateScript(String(contentsOfURL: NSURL(string: curUrl!)!,encoding:String.Encoding.utf8))
//        
//        self.jsContext.exceptionHandler = {(context,exception) in
//            print("exception",exception)
//        }
//        
//        
//    }
    
}




