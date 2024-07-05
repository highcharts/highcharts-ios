!/**
 * Highstock JS v11.4.5 (2024-07-04)
 *
 * Advanced Highcharts Stock tools
 *
 * (c) 2010-2024 Highsoft AS
 * Author: Torstein Honsi
 *
 * License: www.highcharts.com/license
 */function(s){"object"==typeof module&&module.exports?(s.default=s,module.exports=s):"function"==typeof define&&define.amd?define("highcharts/modules/price-indicator",["highcharts","highcharts/modules/stock"],function(i){return s(i),s.Highcharts=i,s}):s("undefined"!=typeof Highcharts?Highcharts:void 0)}(function(s){"use strict";var i=s?s._modules:{};function t(i,t,e,r){i.hasOwnProperty(t)||(i[t]=r.apply(null,e),"function"==typeof CustomEvent&&s.win.dispatchEvent(new CustomEvent("HighchartsModuleLoaded",{detail:{path:t,module:i[t]}})))}t(i,"Extensions/PriceIndication.js",[i["Core/Globals.js"],i["Core/Utilities.js"]],function(s,i){let{composed:t}=s,{addEvent:e,isArray:r,merge:o,pushUnique:a}=i;function c(){let s=this.options,i=s.lastVisiblePrice,t=s.lastPrice;if((i||t)&&"highcharts-navigator-series"!==s.id){let e;let a=this.xAxis,c=this.yAxis,l=c.crosshair,h=c.cross,n=c.crossLabel,d=this.points,u=this.yData.length,b=d.length,p=this.xData[this.xData.length-1],P=this.yData[u-1];if(t&&t.enabled&&(c.crosshair=c.options.crosshair=s.lastPrice,!this.chart.styledMode&&c.crosshair&&c.options.crosshair&&s.lastPrice&&(c.crosshair.color=c.options.crosshair.color=s.lastPrice.color||this.color),c.cross=this.lastPrice,e=r(P)?P[3]:P,this.lastPriceLabel&&this.lastPriceLabel.destroy(),delete c.crossLabel,c.drawCrosshair(null,{x:p,y:e,plotX:a.toPixels(p,!0),plotY:c.toPixels(e,!0)}),this.yAxis.cross&&(this.lastPrice=this.yAxis.cross,this.lastPrice.addClass("highcharts-color-"+this.colorIndex),this.lastPrice.y=e),this.lastPriceLabel=c.crossLabel),i&&i.enabled&&b>0){c.crosshair=c.options.crosshair=o({color:"transparent"},s.lastVisiblePrice),c.cross=this.lastVisiblePrice;let i=d[b-1].isInside?d[b-1]:d[b-2];this.lastVisiblePriceLabel&&this.lastVisiblePriceLabel.destroy(),delete c.crossLabel,c.drawCrosshair(null,i),c.cross&&(this.lastVisiblePrice=c.cross,i&&"number"==typeof i.y&&(this.lastVisiblePrice.y=i.y)),this.lastVisiblePriceLabel=c.crossLabel}c.crosshair=c.options.crosshair=l,c.cross=h,c.crossLabel=n}}return{compose:function(s){a(t,"PriceIndication")&&e(s,"afterRender",c)}}}),t(i,"masters/modules/price-indicator.src.js",[i["Core/Globals.js"],i["Extensions/PriceIndication.js"]],function(s,i){return i.compose(s.Series),s})});