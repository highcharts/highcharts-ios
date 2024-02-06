//
//  DashsboardViewController.m
//  HighFit
//
//  License: www.highcharts.com/license
//  Copyright © 2024 Highsoft AS. All rights reserved.
//

#import "DashboardViewController.h"
#import <Highcharts/Highcharts.h>
#import "OptionsProvider.h"
#import "DataTableViewController.h"

@interface DashboardViewController ()
@property (strong, nonatomic) NSMutableArray *sources;
@property (strong, nonatomic) NSArray *data;
@property (strong, nonatomic) NSString *dataName;
@property (strong, nonatomic) NSMutableArray *charts;
@end

@implementation DashboardViewController

+ (instancetype)sharedDashboard
{
    static DashboardViewController *sharedDashboard = nil;
    static dispatch_once_t onceToken;
    dispatch_once(&onceToken, ^{
        sharedDashboard = [[DashboardViewController alloc] initWithNibName:nil bundle:nil];
    });
    
    return sharedDashboard;
}

- (instancetype)initWithNibName:(NSString *)nibNameOrNil bundle:(NSBundle *)nibBundleOrNil
{
    self = [super initWithNibName:nibNameOrNil bundle:nibBundleOrNil];
    if (self) {
        
        self.title = @"Dashboard";
        
        self.tabBarItem.image = [UIImage imageNamed:@"ic_content_paste_white"];
        
        [self loadSourcesAndData];
        
        self.tableView.rowHeight = 240.0f;
        
        self.tableView.tableHeaderView = [[UIView alloc] initWithFrame:CGRectMake(0.0f, 0.0f, self.tableView.bounds.size.width, 0.01f)];

        self.dataName = @"day";
        
        [self.segment addTarget:self action:@selector(actionSegment:) forControlEvents:UIControlEventValueChanged];
        
        self.tableView.tableHeaderView = nil;
    }
    return self;
}

- (void)viewDidLoad {
    [super viewDidLoad];
    // Do any additional setup after loading the view from its nib.
    
    self.tableView.tableFooterView = [[UIView alloc] initWithFrame:CGRectMake(0, 0, self.view.frame.size.width, 8.0f)];
    
    
    self.tableView.separatorColor = [UIColor clearColor];
    self.tableView.separatorInset = UIEdgeInsetsZero;

}

- (void)viewDidAppear:(BOOL)animated {
    [super viewDidAppear:animated];
    
    [self.tableView reloadData];
}

- (void)didReceiveMemoryWarning {
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}

/*
#pragma mark - Navigation

// In a storyboard-based application, you will often want to do a little preparation before navigation
- (void)prepareForSegue:(UIStoryboardSegue *)segue sender:(id)sender {
    // Get the new view controller using [segue destinationViewController].
    // Pass the selected object to the new view controller.
}
*/

#pragma mark - Table view data source

- (CGFloat)tableView:(UITableView *)tableView heightForRowAtIndexPath:(NSIndexPath *)indexPath
{
    return 250.0f;
}

- (NSInteger)numberOfSectionsInTableView:(UITableView *)tableView {
    return 1;
}

- (NSInteger)tableView:(UITableView *)tableView numberOfRowsInSection:(NSInteger)section {
    return self.data.count;
}

- (UITableViewCell *)tableView:(UITableView *)tableView cellForRowAtIndexPath:(NSIndexPath *)indexPath {
    
    NSMutableDictionary *options = [NSMutableDictionary dictionaryWithDictionary:[self.sources objectAtIndex:indexPath.row]];
    
    UITableViewCell *cell = [tableView dequeueReusableCellWithIdentifier:options[@"chartType"]];
    
    // Configure the cell...
    if (cell == nil) {
        
        cell = [[UITableViewCell alloc] initWithStyle:UITableViewCellStyleDefault reuseIdentifier:options[@"chartType"]];
    
        cell.selectionStyle = UITableViewCellSelectionStyleNone;
    
        HIChartView *chartView = [[HIChartView alloc] initWithFrame:CGRectMake(5.0f, 5.0f, self.view.bounds.size.width-20.0f, 240.0f)];
    
        chartView.backgroundColor = [UIColor clearColor];
    
        NSArray *series = [self.data objectAtIndex:indexPath.row][self.dataName];
        int sum = 0;
        for (NSNumber *number in series) {
            sum += number.integerValue;
        }
        
        options[@"subtitle"] = [NSString stringWithFormat:@"%d %@", sum, options[@"unit"]];
    
        chartView.options = [OptionsProvider provideOptionsForChartType:options series:series type:@"day"];
        
        [cell addSubview:chartView];
    
        [self.charts addObject:chartView];
    
        UIButton *button = [UIButton buttonWithType:UIButtonTypeCustom];
        [button setImage:[UIImage imageNamed:@"ic_info_outline_white"] forState:UIControlStateNormal];
    
        [button setFrame:CGRectMake(self.view.bounds.size.width-20.0f-5.0f-24.0f, 15.0f, 24, 24)];
    
        button.tag = indexPath.row;
        [button addTarget:self action:@selector(showDetailData:) forControlEvents:UIControlEventTouchUpInside];
    
        [chartView addSubview:button];
    }
    else {
        [self updateCellButtonTag:cell newIndex:indexPath.row];
    }
    
    return cell;
}

/*
 // Override to support conditional editing of the table view.
 - (BOOL)tableView:(UITableView *)tableView canEditRowAtIndexPath:(NSIndexPath *)indexPath {
 // Return NO if you do not want the specified item to be editable.
 return YES;
 }
 */

/*
 // Override to support editing the table view.
 - (void)tableView:(UITableView *)tableView commitEditingStyle:(UITableViewCellEditingStyle)editingStyle forRowAtIndexPath:(NSIndexPath *)indexPath {
 if (editingStyle == UITableViewCellEditingStyleDelete) {
 // Delete the row from the data source
 [tableView deleteRowsAtIndexPaths:@[indexPath] withRowAnimation:UITableViewRowAnimationFade];
 } else if (editingStyle == UITableViewCellEditingStyleInsert) {
 // Create a new instance of the appropriate class, insert it into the array, and add a new row to the table view
 }
 }
 */

/*
 // Override to support rearranging the table view.
 - (void)tableView:(UITableView *)tableView moveRowAtIndexPath:(NSIndexPath *)fromIndexPath toIndexPath:(NSIndexPath *)toIndexPath {
 }
 */

/*
 // Override to support conditional rearranging of the table view.
 - (BOOL)tableView:(UITableView *)tableView canMoveRowAtIndexPath:(NSIndexPath *)indexPath {
 // Return NO if you do not want the item to be re-orderable.
 return YES;
 }
 */

#pragma mark - Table view delegate

/*
// In a xib-based application, navigation from a table can be handled in -tableView:didSelectRowAtIndexPath:
- (void)tableView:(UITableView *)tableView didSelectRowAtIndexPath:(NSIndexPath *)indexPath {
    // Navigation logic may go here, for example:
    // Create the next view controller.
    
    // Pass the selected object to the new view controller.
    
    // Push the view controller.
}
*/

/*
 #pragma mark - Navigation
 
 // In a storyboard-based application, you will often want to do a little preparation before navigation
 - (void)prepareForSegue:(UIStoryboardSegue *)segue sender:(id)sender {
 // Get the new view controller using [segue destinationViewController].
 // Pass the selected object to the new view controller.
 }
 */

#pragma mark - Additional methods

- (void)dataSourceAdd:(NSDictionary*)dataSource
{
    if (![self.sources containsObject:dataSource]) {
        NSMutableArray *tmp = [NSMutableArray arrayWithArray:self.sources];
        [tmp addObject:dataSource];
        self.sources = [tmp copy];
        
        [[NSUserDefaults standardUserDefaults] setValue:self.sources forKey:@"sources"];
    }
    
    [self loadSourcesAndData];
    [self.tableView reloadData];
}

- (void)dataSourceRem:(NSDictionary*)dataSource
{
    if ([self.sources containsObject:dataSource]) {
        NSMutableArray *tmp = [NSMutableArray arrayWithArray:self.sources];
        [tmp removeObject:dataSource];
        self.sources = [tmp copy];
        
        [[NSUserDefaults standardUserDefaults] setValue:self.sources forKey:@"sources"];
    }
    
    [self loadSourcesAndData];
    [self.tableView reloadData];
}

- (void) updateCellButtonTag: (UITableViewCell*) cell newIndex:(NSInteger) index
{
    for (UIView *view in [cell subviews]) {
        if([view isKindOfClass:[HIChartView class]]) {
            for (UIView *subview in [view subviews]) {
                if([subview isKindOfClass:[UIButton class]]) {
                    subview.tag = index;
                }
            }
        }
    }
}

- (IBAction)actionSegment:(UISegmentedControl*)sender
{
    switch (sender.selectedSegmentIndex) {
        case 0:
            self.dataName = @"day";
            break;
        case 1:
            self.dataName = @"week";
            break;
        case 2:
            self.dataName = @"month";
            break;
        case 3:
            self.dataName = @"year";
            break;
        default:
            break;
    }
    
    [self.tableView reloadData];
}

- (void)loadSourcesAndData
{
    self.data = [NSArray array];
    
    self.sources = [[NSUserDefaults standardUserDefaults] valueForKey:@"sources"];
    
    NSMutableArray *tmpData = [NSMutableArray array];
    for (NSDictionary *source in self.sources) {
        
        NSData *data = [NSData dataWithContentsOfFile:[[NSBundle mainBundle] pathForResource:source[@"source"] ofType:@"json"]];
        NSError *error = nil;
        
        [tmpData addObject:[NSJSONSerialization JSONObjectWithData:data options:kNilOptions error:&error]];
    }
    self.data = [tmpData copy];
}

- (void)showDetailData:(UIButton*)sender
{
    [self.tabBarController setSelectedIndex:1];
    
    DataTableViewController *dataView = [[DataTableViewController alloc] initWithNibName:@"DataTableViewController" bundle:nil];
    
    // Pass the selected object to the new view controller.
    
    NSMutableDictionary *options = [NSMutableDictionary dictionaryWithDictionary:[self.sources objectAtIndex:sender.tag]];
    
    [dataView setConfiguration:options];
    
    UINavigationController *navController = (UINavigationController*)self.tabBarController.selectedViewController;
    if ([navController.visibleViewController isKindOfClass:[DataTableViewController class]]) {
        [navController popViewControllerAnimated:NO];
    }
    
    //Push the view controller
    [navController pushViewController:dataView animated:YES];
}

@end
