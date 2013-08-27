//
//  ViewController.m
//  BlockUse
//
//  Created by 紫冬 on 13-8-27.
//  Copyright (c) 2013年 qsji. All rights reserved.
//

#import "ViewController.h"

@interface ViewController ()

@end

@implementation ViewController
@synthesize myBlock = _myBlock;
@synthesize length = _length;
@synthesize block = _block;

- (void)viewDidLoad
{
    [super viewDidLoad];
	// Do any additional setup after loading the view, typically from a nib.
    
    //分别定义两个外部的局部变量
    int m = 0;
    __block int n;
    
    //声明一个块变量
    int (^myBlock)(int);
    
    //定义块
    myBlock = ^(int num){
        NSLog(@"execute block");
        
        //操作宿主类的属性和方法
        self.length = 100;
        [self print];
        
        //操作普通的外部局部变量
        num = m + 3;
        //m = 5;   对普通外部局部变量不能执行写的操作
        
        //操作用__block修饰的外部局部变量
        n = n + 1;
        
        return num;
    };
    
    self.myBlock = myBlock;
    
    //调用块
    NSLog(@"值是：%d", self.myBlock(4));
    
    
    
    //给块赋值，定义
    self.block = ^(void){
        NSLog(@"调用块变量，并执行");
    };
    //调用块
    self.block();
    
    
    //块的回调测试，通过块回调，不用设置委托对象，因为块本身就有操作宿主类数据的能力
    MyHandler *handler = [[MyHandler alloc] init];
    [handler handle:^{
        self.length = 2 * 6;
        NSLog(@"通过回调来操作宿主类的数据length,length = %d", self.length);
    }];
    
}

-(void)print
{
    NSLog(@"在块中调用宿主类的方法");
}

- (void)didReceiveMemoryWarning
{
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}

@end
