//
//  DataTableViewController.m
//  HighFit
//
//  License: www.highcharts.com/license
//  Copyright © 2023 Highsoft AS. All rights reserved.
//

#import "DataTableViewController.h"
#import "DataViewController.h"
#import <Highcharts/Highcharts.h>
#import "DashboardViewController.h"
#import "OptionsProvider.h"

@interface DataTableViewController ()
@property (strong, nonatomic) NSString *chartType;
@property (strong, nonatomic) NSDictionary *data;
@property (strong, nonatomic) UIView *chartViewBase;
@property (strong, nonatomic) HIChartView *chartView;

@property (strong, nonatomic) UISwitch *switchView;
@end

@implementation DataTableViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    
    // Uncomment the following line to preserve selection between presentations.
    // self.clearsSelectionOnViewWillAppear = NO;
    
    // Uncomment the following line to display an Edit button in the navigation bar for this view controller.
    // self.navigationItem.rightBarButtonItem = self.editButtonItem;
    
    self.chartType = self.configuration[@"chartType"];
    
    self.tableView = [[UITableView alloc] initWithFrame:self.view.bounds style:UITableViewStyleGrouped];
    
    NSData *data = [NSData dataWithContentsOfFile:[[NSBundle mainBundle] pathForResource:self.configuration[@"source"] ofType:@"json"]];
    NSError *error = nil;
    self.data = [NSJSONSerialization JSONObjectWithData:data options:kNilOptions error:&error];
    
    self.title = self.configuration[@"title"];
    
    self.tableView.tableHeaderView = self.toolbar;
    
    self.tableView.tableFooterView = [[UIView alloc] initWithFrame:CGRectZero];
    
    [self.segment addTarget:self action:@selector(actionSegment:) forControlEvents:UIControlEventValueChanged];
    
    self.switchView = [[UISwitch alloc] init];
    [self.switchView addTarget:self action:@selector(actionSwitch:) forControlEvents:UIControlEventValueChanged];
}

- (void)viewWillAppear:(BOOL)animated {
    [super viewWillAppear:animated];
    
    self.switchView.on = [self isSwitchOn];
}

- (void)didReceiveMemoryWarning {
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}

#pragma mark - Table view data source

- (NSInteger)numberOfSectionsInTableView:(UITableView *)tableView {
    return 1;
}

- (NSInteger)tableView:(UITableView *)tableView numberOfRowsInSection:(NSInteger)section {
    return 3;
}

- (UIView*)tableView:(UITableView *)tableView viewForHeaderInSection:(NSInteger)section
{
    if (!self.chartViewBase) {
        
        self.chartViewBase = [[UIView alloc] initWithFrame:CGRectMake(0.0f, 0.0f, self.view.frame.size.width, 260.0f)];
        self.chartViewBase.backgroundColor = [UIColor whiteColor];
        NSMutableDictionary *tmpOptions = [NSMutableDictionary dictionaryWithDictionary:self.configuration];
        tmpOptions[@"exporting"] = @YES;
        self.chartView = [[HIChartView alloc] initWithFrame:CGRectMake(5.0f, 5.0f, self.view.frame.size.width-20, 240.0f)];
        int sum = 0;
        for (NSNumber *number in self.data[@"day"]) {
            sum += number.integerValue;
        }
        
        tmpOptions[@"subtitle"] = [NSString stringWithFormat:@"%d %@", sum, tmpOptions[@"unit"]];

        self.chartView.options = [OptionsProvider provideOptionsForChartType:tmpOptions series:self.data[@"day"] type:@"day"];
        self.chartView.viewController = self;
        
        [self.chartViewBase addSubview:self.chartView];
    }
    
    return self.chartViewBase;
}

- (CGFloat)tableView:(UITableView *)tableView heightForHeaderInSection:(NSInteger)section
{
    return 260.0f;
}

- (UITableViewCell *)tableView:(UITableView *)tableView cellForRowAtIndexPath:(NSIndexPath *)indexPath {
    UITableViewCell *cell = [tableView dequeueReusableCellWithIdentifier:@"HighFitCellData"];
    
    // Configure the cell...
    if (cell == nil) {
        cell = [[UITableViewCell alloc] initWithStyle:UITableViewCellStyleDefault reuseIdentifier:@"HighFitCellData"];
    }
    
    cell.accessoryView = nil;
    cell.textLabel.text = nil;
    cell.accessoryType = UITableViewCellAccessoryNone;
    
    if (indexPath.row == 0) {
        cell.selectionStyle = UITableViewCellSelectionStyleNone;
        cell.textLabel.text = @"Show on Dashboard.";
        
        cell.accessoryView = self.switchView;
    }
    
    if (indexPath.row == 1) {
        cell.accessoryType = UITableViewCellAccessoryDisclosureIndicator;
        cell.textLabel.text = @"Show all Data";
    }
    
    if (indexPath.row == 2) {
        cell.selectionStyle = UITableViewCellSelectionStyleNone;
        cell.textLabel.text = @"Unit";
        
        UILabel *label = [[UILabel alloc] init];
        [label setText:self.configuration[@"unit"]];
        [label setFont:[UIFont systemFontOfSize:16.0f]];
        [label setTextColor:[UIColor lightGrayColor]];
        [label sizeToFit];
        
        cell.accessoryView = label;
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

// In a xib-based application, navigation from a table can be handled in -tableView:didSelectRowAtIndexPath:
- (void)tableView:(UITableView *)tableView didSelectRowAtIndexPath:(NSIndexPath *)indexPath {
    // Navigation logic may go here, for example:
    // Create the next view controller.
    
    [tableView deselectRowAtIndexPath:indexPath animated:YES];
    
    if (indexPath.row != 1) {
        return;
    }
    
    DataViewController *detailViewController = [[DataViewController alloc] initWithNibName:@"DataViewController" bundle:nil];
    
    // Pass the selected object to the new view controller.
    detailViewController.unit = self.configuration[@"unit"];
    detailViewController.data = self.data[@"all"];
    
    // Push the view controller.
    [self.navigationController pushViewController:detailViewController animated:YES];
}

/*
#pragma mark - Navigation

// In a storyboard-based application, you will often want to do a little preparation before navigation
- (void)prepareForSegue:(UIStoryboardSegue *)segue sender:(id)sender {
    // Get the new view controller using [segue destinationViewController].
    // Pass the selected object to the new view controller.
}
*/

#pragma mark - Additinal methods

- (void)actionSwitch:(UISwitch*)actionSwitch
{
    // Show or hide chart on dashboard.
    if (actionSwitch.isOn) {
        [[DashboardViewController sharedDashboard] dataSourceAdd: self.configuration];
    } else {
        [[DashboardViewController sharedDashboard] dataSourceRem: self.configuration];
    }
}

- (IBAction)actionSegment:(UISegmentedControl*)sender
{
    NSString *dataName = @"day";
    
    switch (sender.selectedSegmentIndex) {
        case 0:
            dataName = @"day";
            break;
        case 1:
            dataName = @"week";
            break;
        case 2:
            dataName = @"month";
            break;
        case 3:
            dataName = @"year";
            break;
        default:
            break;
    }
    
    NSMutableDictionary *tmpOptions = [NSMutableDictionary dictionaryWithDictionary:self.configuration];
    tmpOptions[@"exporting"] = @YES;
    
    int sum = 0;
    for (NSNumber *number in self.data[dataName]) {
        sum += number.integerValue;
    }
    
    tmpOptions[@"subtitle"] = [NSString stringWithFormat:@"%d %@", sum, tmpOptions[@"unit"]];
    
    self.chartView.options = [OptionsProvider provideOptionsForChartType:tmpOptions series:self.data[dataName] type:dataName];
}

- (BOOL)isSwitchOn
{
    NSArray *sources = [[NSUserDefaults standardUserDefaults] valueForKey:@"sources"];
    for (NSDictionary *item in sources) {
        if ([[item valueForKey:@"source"] isEqualToString:self.configuration[@"source"]]) {
            return YES;
        }
    }
    return NO;
}

@end
