//
//  ViewController.h
//  BlockUse
//
//  Created by 紫冬 on 13-8-27.
//  Copyright (c) 2013年 qsji. All rights reserved.
//

/*
 块的使用：
 第一步：声明一个块对象，声明格式
 返回值类型 (^块对象名字)(参数列表);在声明的时候，可以有形参，也可以没有形参
 比如：
 int (^myBlock)(int);  //只有类型，没有形参，当然也可以有形参
 上面表示声明一个块对象，返回值是int类型，块对象名字叫做myBlock，参数类型列表是int类型
 
 第二步：定义该块对象，也就是实现，注意一定要加上分号，定义的格式：
 ^(参数列表){    };
 比如：
 myBlock = ^(int num){
 return num;
 };
 
 第三步：调用该block，调用格式
 块对象名字(参数);
 比如：
 NSLog(@"值是：%d", myBlock(4));
 
 块作为数据成员的使用；
 第一步：先声明块数据成员   int (^_myBlock)(int);
 第二步：设置属性，属性的关键字是assign，retain还是copy，是由块的返回值来确定的
        @property(nonatomic, assign)int (^myBlock)(int);
 第三部：实现属性
        @synthesize myBlock = _myBlock;
 第四步：给块对象变量赋值
        self.myBlock = myBlock;
 第五步：引用块
        比如：
        myBlock(4);   //这是直接当做函数来使用(就像C/C++/java调用函数执行一样)，也即是直接执行该块。
        self.myBlock(4);   //这是直接当做函数来使用(就像C/C++/java调用函数执行一样)，也即是直接执行该块。
        NSLog(@"值是：%d", self.myBlock(4));  //将块作为返回值
 
 注意：
 block其实就是匿名函数，在oc中block块是一个对象。
 但是Block 又是一个标准 Objective-C 对象。 因为他们是对象， 他们可以作为参数传递， 作为方法或函数的返回值， 赋值给变量。
 block无论是作为匿名函数，还是一个对象，都相当于JAVA中的内部类或者是匿名类，因此它具有操作宿主类中数据成员和方法的权限。
 
 块对外部的数据（外部局部变量）只拥有只读权限，不能更改。对宿主类的属性，和传入的参数是具有可读可写权限的。要想对外部局部变量具有写的权限，
 那么必须再声明定义外部局部变量的时候利用关键__block来修饰。
 */


#import <UIKit/UIKit.h>
#import "MyHandler.h"

//当然，我们还可以为一个block，定义一个block别名，如下

typedef void (^Block_Type)(void);   //这里我们就定义了一个没有参数，没有返回值的块类型

@interface ViewController : UIViewController
{
    int (^_myBlock)(int);  //直接定义一个块变量
    int _length;
    
    Block_Type _block;     //定义一个块变量
}

@property(nonatomic, assign)int (^myBlock)(int);
@property(nonatomic, assign)int length;
@property(nonatomic, copy)Block_Type block;

-(void)print;

@end
