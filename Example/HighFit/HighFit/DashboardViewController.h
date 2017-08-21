//
//  DashsboardViewController.h
//  HighFit
//
//  License: www.highcharts.com/license
//  Copyright © 2016-2017 Highsoft AS. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface DashboardViewController : UITableViewController

@property (weak, nonatomic) IBOutlet UIToolbar *toolbar;
@property (weak, nonatomic) IBOutlet UISegmentedControl *segment;

+ (id)sharedDashboard;

- (void)dataSourceAdd:(NSDictionary*)dataSource;
- (void)dataSourceRem:(NSDictionary*)dataSource;

@end
