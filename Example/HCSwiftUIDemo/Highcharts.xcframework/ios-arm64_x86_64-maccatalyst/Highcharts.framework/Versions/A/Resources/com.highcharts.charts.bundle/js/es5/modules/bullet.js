!/**
 * Highcharts JS v11.4.3 (2024-05-22)
 *
 * Bullet graph series type for Highcharts
 *
 * (c) 2010-2024 Kacper Madej
 *
 * License: www.highcharts.com/license
 */function(t){"object"==typeof module&&module.exports?(t.default=t,module.exports=t):"function"==typeof define&&define.amd?define("highcharts/modules/bullet",["highcharts"],function(e){return t(e),t.Highcharts=e,t}):t("undefined"!=typeof Highcharts?Highcharts:void 0)}(function(t){"use strict";var e=t?t._modules:{};function r(t,e,r,o){t.hasOwnProperty(e)||(t[e]=o.apply(null,r),"function"==typeof CustomEvent&&window.dispatchEvent(new CustomEvent("HighchartsModuleLoaded",{detail:{path:e,module:t[e]}})))}r(e,"Series/Bullet/BulletPoint.js",[e["Series/Column/ColumnSeries.js"]],function(t){var e,r=this&&this.__extends||(e=function(t,r){return(e=Object.setPrototypeOf||({__proto__:[]})instanceof Array&&function(t,e){t.__proto__=e}||function(t,e){for(var r in e)Object.prototype.hasOwnProperty.call(e,r)&&(t[r]=e[r])})(t,r)},function(t,r){if("function"!=typeof r&&null!==r)throw TypeError("Class extends value "+String(r)+" is not a constructor or null");function o(){this.constructor=t}e(t,r),t.prototype=null===r?Object.create(r):(o.prototype=r.prototype,new o)});return function(t){function e(){return null!==t&&t.apply(this,arguments)||this}return r(e,t),e.prototype.destroy=function(){this.targetGraphic&&(this.targetGraphic=this.targetGraphic.destroy()),t.prototype.destroy.apply(this,arguments)},e}(t.prototype.pointClass)}),r(e,"Series/Bullet/BulletSeriesDefaults.js",[],function(){return{targetOptions:{width:"140%",height:3,borderWidth:0,borderRadius:0},tooltip:{pointFormat:'<span style="color:{series.color}">●</span> {series.name}: <b>{point.y}</b>. Target: <b>{point.target}</b><br/>'}}}),r(e,"Series/Bullet/BulletSeries.js",[e["Series/Bullet/BulletPoint.js"],e["Series/Bullet/BulletSeriesDefaults.js"],e["Series/Column/ColumnSeries.js"],e["Core/Series/SeriesRegistry.js"],e["Core/Utilities.js"]],function(t,e,r,o,i){var n,s=this&&this.__extends||(n=function(t,e){return(n=Object.setPrototypeOf||({__proto__:[]})instanceof Array&&function(t,e){t.__proto__=e}||function(t,e){for(var r in e)Object.prototype.hasOwnProperty.call(e,r)&&(t[r]=e[r])})(t,e)},function(t,e){if("function"!=typeof e&&null!==e)throw TypeError("Class extends value "+String(e)+" is not a constructor or null");function r(){this.constructor=t}n(t,e),t.prototype=null===e?Object.create(e):(r.prototype=e.prototype,new r)}),a=i.extend,l=i.isNumber,p=i.merge,u=i.pick,c=i.relativeLength,h=function(t){function o(){return null!==t&&t.apply(this,arguments)||this}return s(o,t),o.prototype.drawPoints=function(){var e=this.chart,r=this.options,o=r.animationLimit||250;t.prototype.drawPoints.apply(this,arguments);for(var i=0,n=this.points;i<n.length;i++){var s=n[i],a=s.options,h=s.target,d=s.y,f=void 0,y=s.targetGraphic,g=void 0,m=void 0,b=void 0,v=void 0;if(l(h)&&null!==h){m=(b=p(r.targetOptions,a.targetOptions)).height;var x=s.shapeArgs;s.dlBox&&x&&!l(x.width)&&(x=s.dlBox),g=c(b.width,x.width),v=this.yAxis.translate(h,!1,!0,!1,!0)-b.height/2-.5,f=this.crispCol.apply({chart:e,borderWidth:b.borderWidth,options:{crisp:r.crisp}},[x.x+x.width/2-g/2,v,g,m]),y?(y[e.pointCount<o?"animate":"attr"](f),l(d)&&null!==d?y.element.point=s:y.element.point=void 0):s.targetGraphic=y=e.renderer.rect().attr(f).add(this.group),e.styledMode||y.attr({fill:u(b.color,a.color,this.zones.length&&(s.getZone.call({series:this,x:s.x,y:h,options:{}}).color||this.color)||void 0,s.color,this.color),stroke:u(b.borderColor,s.borderColor,this.options.borderColor),"stroke-width":b.borderWidth,r:b.borderRadius}),l(d)&&null!==d&&(y.element.point=s),y.addClass(s.getClassName()+" highcharts-bullet-target",!0)}else y&&(s.targetGraphic=y.destroy())}},o.prototype.getExtremes=function(e){var r=t.prototype.getExtremes.call(this,e),o=this.targetData;if(o&&o.length){var i=t.prototype.getExtremes.call(this,o);l(i.dataMin)&&(r.dataMin=Math.min(u(r.dataMin,1/0),i.dataMin)),l(i.dataMax)&&(r.dataMax=Math.max(u(r.dataMax,-1/0),i.dataMax))}return r},o.defaultOptions=p(r.defaultOptions,e),o}(r);return a(h.prototype,{parallelArrays:["x","y","target"],pointArrayMap:["y","target"]}),h.prototype.pointClass=t,o.registerSeriesType("bullet",h),h}),r(e,"masters/modules/bullet.src.js",[e["Core/Globals.js"]],function(t){return t})});