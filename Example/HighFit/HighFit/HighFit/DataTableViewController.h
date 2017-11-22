//
//  DataTableViewController.h
//  HighFit
//
//  License: www.highcharts.com/license
//  Copyright © 2016 Highsoft AS. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface DataTableViewController : UITableViewController

@property (weak, nonatomic) IBOutlet UIToolbar *toolbar;
@property (weak, nonatomic) IBOutlet UISegmentedControl *segment;

@property (strong, nonatomic) NSDictionary *configuration;

@end
