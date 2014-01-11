//
//  ViewController.m
//  IOS7Crypt
//
//  Created by Andrew Pennebaker on 1/11/14.
//  Copyright (c) 2014 Andrew Pennebaker. All rights reserved.
//

#import "ViewController.h"
#import "ios7crypt.h"

@interface ViewController ()

@end

@implementation ViewController

@synthesize passwordField;
@synthesize hashField;

-(IBAction) encryptButton: (id) sender {
  NSString *password = passwordField.text;

  const char* passwordAsCString = [password UTF8String];

  char* hashAsCString = (char *) calloc((size_t) strlen(passwordAsCString) * 2 + 3, sizeof(char));

  encrypt_ios7(passwordAsCString, hashAsCString);

  NSString *hash = [NSString stringWithUTF8String: hashAsCString];

  hashField.text = hash;
}

-(IBAction) decryptButton: (id) sender {
  NSString *hash = hashField.text;

  const char* hashAsCString = [hash UTF8String];

  char* passwordAsCString = (char *) calloc((size_t) strlen(hashAsCString) / 2, sizeof(char));

  decrypt_ios7(hashAsCString, passwordAsCString);

  NSString *password = [NSString stringWithUTF8String: passwordAsCString];
  
  passwordField.text = password;
}

- (void)viewDidLoad
{
    [super viewDidLoad];
	// Do any additional setup after loading the view, typically from a nib.
}

- (void)didReceiveMemoryWarning
{
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}

@end
