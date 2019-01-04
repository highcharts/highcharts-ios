/**
* (c) 2009-2018 Highsoft AS
*
* License: www.highcharts.com/license
* For commercial usage, a valid license is required. To purchase a license for Highcharts iOS, please see our website: https://shop.highsoft.com/
* In case of questions, please contact sales@highsoft.com
*/

#import "HIChartsJSONSerializable.h"


/**
Translations for all field names used in popup.
*/
@interface HIPopup: HIChartsJSONSerializable

@property(nonatomic, readwrite) NSString *horizontalLine;
@property(nonatomic, readwrite) NSString *backgroundColors;
@property(nonatomic, readwrite) NSString *series;
@property(nonatomic, readwrite) NSString *labels;
@property(nonatomic, readwrite) NSString *height;
@property(nonatomic, readwrite) NSString *addButton;
@property(nonatomic, readwrite) NSString *verticalCounter;
@property(nonatomic, readwrite) NSString *stroke;
@property(nonatomic, readwrite) NSString *fibonacci;
@property(nonatomic, readwrite) NSString *measure;
@property(nonatomic, readwrite) NSString *removeButton;
@property(nonatomic, readwrite) NSString *verticalArrow;
@property(nonatomic, readwrite) NSString *fill;
@property(nonatomic, readwrite) NSString *borderColor;
@property(nonatomic, readwrite) NSString *shapes;
@property(nonatomic, readwrite) NSString *style;
@property(nonatomic, readwrite) NSString *crosshairX;
@property(nonatomic, readwrite) NSString *crosshairY;
@property(nonatomic, readwrite) NSString *arrowLine;
@property(nonatomic, readwrite) NSString *typeOptions;
@property(nonatomic, readwrite) NSString *label;
@property(nonatomic, readwrite) NSString *connector;
@property(nonatomic, readwrite) NSString *arrowRay;
@property(nonatomic, readwrite) NSString *fontSize;
@property(nonatomic, readwrite) NSString *backgroundColor;
@property(nonatomic, readwrite) NSString *arrowSegment;
@property(nonatomic, readwrite) NSString *ray;
@property(nonatomic, readwrite) NSString *verticalLabel;
@property(nonatomic, readwrite) NSString *borderRadius;
@property(nonatomic, readwrite) NSString *volume;
@property(nonatomic, readwrite) NSString *strokeWidth;
@property(nonatomic, readwrite) NSString *format;
@property(nonatomic, readwrite) NSString *labelOptions;
@property(nonatomic, readwrite) NSString *elliott5;
@property(nonatomic, readwrite) NSString *elliott3;
@property(nonatomic, readwrite) NSString *padding;
@property(nonatomic, readwrite) NSString *simpleShapes;
@property(nonatomic, readwrite) NSString *verticalLine;
@property(nonatomic, readwrite) NSString *parallelChannel;
@property(nonatomic, readwrite) NSString *background;
@property(nonatomic, readwrite) NSString *saveButton;
@property(nonatomic, readwrite) NSString *line;
@property(nonatomic, readwrite) NSString *segment;
@property(nonatomic, readwrite) NSString *circle;
@property(nonatomic, readwrite) NSString *color;
@property(nonatomic, readwrite) NSString *measureX;
@property(nonatomic, readwrite) NSString *measureY;
@property(nonatomic, readwrite) NSString *innerBackground;
@property(nonatomic, readwrite) NSString *name;
@property(nonatomic, readwrite) NSString *measureXY;
@property(nonatomic, readwrite) NSString *outerBackground;
@property(nonatomic, readwrite) NSString *rectangle;
@property(nonatomic, readwrite) NSString *lines;
@property(nonatomic, readwrite) NSString *pitchfork;
@property(nonatomic, readwrite) NSString *crooked5;
@property(nonatomic, readwrite) NSString *tunnel;
@property(nonatomic, readwrite) NSString *flags;
@property(nonatomic, readwrite) NSString *borderWidth;
@property(nonatomic, readwrite) NSString *crooked3;
@property(nonatomic, readwrite) NSString *title;
@property(nonatomic, readwrite) NSString *editButton;
@property(nonatomic, readwrite) NSString *shapeOptions;
@property(nonatomic, readwrite) NSString *infinityLine;

-(NSDictionary *)getParams;

@end
