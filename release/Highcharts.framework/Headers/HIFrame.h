/**
* (c) 2009-2017 Highsoft AS
*
* License: www.highcharts.com/license
* For commercial usage, a valid license is required. To purchase a license for Highcharts iOS, please see our website: https://shop.highsoft.com/
* In case of questions, please contact sales@highsoft.com
*/

#import "HIRight.h"
#import "HITop.h"
#import "HIBack.h"
#import "HISide.h"
#import "HIFront.h"
#import "HILeft.h"
#import "HIBottom.h"


/**
* description: Provides the option to draw a frame around the charts by defining
a bottom, front and back panel.
*/
@interface HIFrame: HIChartsJSONSerializable

/**
* description: Whether the frames are visible.
* default: default
*/
@property(nonatomic, readwrite) NSString *visible;
/**
* description: General pixel thickness for the frame faces.
* default: 1
*/
@property(nonatomic, readwrite) NSNumber *size;
/**
* description: The right of the frame around a 3D chart.
*/
@property(nonatomic, readwrite) HIRight *right;
/**
* description: The top of the frame around a 3D chart.
*/
@property(nonatomic, readwrite) HITop *top;
/**
* description: The back side of the frame around a 3D chart.
*/
@property(nonatomic, readwrite) HIBack *back;
/**
* description: Note: As of v5.0.12, frame.left or frame.right should be used
instead.
The side for the frame around a 3D chart.
*/
@property(nonatomic, readwrite) HISide *side;
/**
* description: The front of the frame around a 3D chart.
*/
@property(nonatomic, readwrite) HIFront *front;
/**
* description: The left side of the frame around a 3D chart.
*/
@property(nonatomic, readwrite) HILeft *left;
/**
* description: The bottom of the frame around a 3D chart.
*/
@property(nonatomic, readwrite) HIBottom *bottom;

-(NSDictionary *)getParams;

@end
