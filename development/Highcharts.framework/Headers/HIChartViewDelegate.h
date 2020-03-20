/**
 * (c) 2009-2018 Highsoft AS
 *
 * License: www.highcharts.com/license
 * For commercial usage, a valid license is required. To purchase a license for Highcharts iOS, please see our website: https://shop.highsoft.com/
 * In case of questions, please contact sales@highsoft.com
 */

#import <Foundation/Foundation.h>

@class HIChartView;

/**
 * The delegate of the HIChartView.
 */
@protocol HIChartViewDelegate <NSObject>

/**
 *  Called when drawing is complete.
 */
- (void) chartViewDidLoad: (HIChartView *) chart;

@end
