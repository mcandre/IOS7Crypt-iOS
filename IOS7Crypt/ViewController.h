//
//  ViewController.h
//  IOS7Crypt
//
//  Created by Andrew Pennebaker on 1/11/14.
//  Copyright (c) 2014 Andrew Pennebaker. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface ViewController : UIViewController

@property (strong, nonatomic) IBOutlet UITextField *passwordField;
@property (strong, nonatomic) IBOutlet UITextField *hashField;

- (BOOL) textFieldShouldReturn: (UITextField *) textField;

-(IBAction) encryptButton: (id) sender;
-(IBAction) decryptButton: (id) sender;

@end
