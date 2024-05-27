!/**
 * Highcharts JS v11.4.3 (2024-05-22)
 *
 * Plugin for displaying a message when there is no data visible in chart.
 *
 * (c) 2010-2024 Highsoft AS
 * Author: Oystein Moseng
 *
 * License: www.highcharts.com/license
 */function(t){"object"==typeof module&&module.exports?(t.default=t,module.exports=t):"function"==typeof define&&define.amd?define("highcharts/modules/no-data-to-display",["highcharts"],function(a){return t(a),t.Highcharts=a,t}):t("undefined"!=typeof Highcharts?Highcharts:void 0)}(function(t){"use strict";var a=t?t._modules:{};function o(t,a,o,e){t.hasOwnProperty(a)||(t[a]=e.apply(null,o),"function"==typeof CustomEvent&&window.dispatchEvent(new CustomEvent("HighchartsModuleLoaded",{detail:{path:a,module:t[a]}})))}o(a,"Extensions/NoDataToDisplay/NoDataDefaults.js",[],function(){return{lang:{noData:"No data to display"},noData:{attr:{zIndex:1},position:{x:0,y:0,align:"center",verticalAlign:"middle"},style:{fontWeight:"bold",fontSize:"0.8em",color:"#666666"}}}}),o(a,"Extensions/NoDataToDisplay/NoDataToDisplay.js",[a["Core/Renderer/HTML/AST.js"],a["Extensions/NoDataToDisplay/NoDataDefaults.js"],a["Core/Utilities.js"]],function(t,a,o){let{addEvent:e,extend:n,merge:s}=o;function i(){let t=this.series||[],a=t.length;for(;a--;)if(t[a].hasData()&&!t[a].options.isInternal)return!0;return this.loadingShown}function l(){this.noDataLabel&&(this.noDataLabel=this.noDataLabel.destroy())}function r(a){let o=this.options,e=a||o&&o.lang.noData||"",s=o&&(o.noData||{});this.renderer&&(this.noDataLabel||(this.noDataLabel=this.renderer.label(e,0,0,void 0,void 0,void 0,s.useHTML,void 0,"no-data").add()),this.styledMode||this.noDataLabel.attr(t.filterUserAttributes(s.attr||{})).css(s.style||{}),this.noDataLabel.align(n(this.noDataLabel.getBBox(),s.position||{}),!1,"plotBox"))}function d(){this.hasData()?this.hideNoData():this.showNoData()}return{compose:function(t,o){let n=t.prototype;n.showNoData||(n.hasData=i,n.hideNoData=l,n.showNoData=r,e(t,"render",d),s(!0,o,a))}}}),o(a,"masters/modules/no-data-to-display.src.js",[a["Core/Globals.js"],a["Extensions/NoDataToDisplay/NoDataToDisplay.js"]],function(t,a){return a.compose(t.Chart,t.defaultOptions),t})});