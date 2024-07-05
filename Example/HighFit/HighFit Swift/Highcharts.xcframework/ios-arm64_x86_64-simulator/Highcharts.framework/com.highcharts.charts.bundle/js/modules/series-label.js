!/**
 * Highcharts JS v11.4.5 (2024-07-04)
 *
 * (c) 2009-2024 Torstein Honsi
 *
 * License: www.highcharts.com/license
 */function(t){"object"==typeof module&&module.exports?(t.default=t,module.exports=t):"function"==typeof define&&define.amd?define("highcharts/modules/series-label",["highcharts"],function(e){return t(e),t.Highcharts=e,t}):t("undefined"!=typeof Highcharts?Highcharts:void 0)}(function(t){"use strict";var e=t?t._modules:{};function o(e,o,r,i){e.hasOwnProperty(o)||(e[o]=i.apply(null,r),"function"==typeof CustomEvent&&t.win.dispatchEvent(new CustomEvent("HighchartsModuleLoaded",{detail:{path:o,module:e[o]}})))}o(e,"Extensions/SeriesLabel/SeriesLabelDefaults.js",[],function(){return{enabled:!0,connectorAllowed:!1,connectorNeighbourDistance:24,format:void 0,formatter:void 0,minFontSize:null,maxFontSize:null,onArea:null,style:{fontSize:"0.8em",fontWeight:"bold"},useHTML:!1,boxesToAvoid:[]}}),o(e,"Extensions/SeriesLabel/SeriesLabelUtilities.js",[],function(){function t(t,e,o,r,i,a){let n=(a-e)*(o-t)-(r-e)*(i-t);return n>0||!(n<0)}function e(e,o,r,i,a,n,s,l){return t(e,o,a,n,s,l)!==t(r,i,a,n,s,l)&&t(e,o,r,i,a,n)!==t(e,o,r,i,s,l)}return{boxIntersectLine:function(t,o,r,i,a,n,s,l){return e(t,o,t+r,o,a,n,s,l)||e(t+r,o,t+r,o+i,a,n,s,l)||e(t,o+i,t+r,o+i,a,n,s,l)||e(t,o,t,o+i,a,n,s,l)},intersectRect:function(t,e){return!(e.left>t.right||e.right<t.left||e.top>t.bottom||e.bottom<t.top)}}}),o(e,"Extensions/SeriesLabel/SeriesLabel.js",[e["Core/Animation/AnimationUtilities.js"],e["Core/Templating.js"],e["Core/Defaults.js"],e["Core/Globals.js"],e["Extensions/SeriesLabel/SeriesLabelDefaults.js"],e["Extensions/SeriesLabel/SeriesLabelUtilities.js"],e["Core/Utilities.js"]],function(t,e,o,r,i,a,n){let{animObject:s}=t,{format:l}=e,{setOptions:h}=o,{composed:c}=r,{boxIntersectLine:p,intersectRect:u}=a,{addEvent:d,extend:f,fireEvent:x,isNumber:b,pick:m,pushUnique:g,syncTimeout:y}=n;function X(t,e,o,r,i){let a=t.chart,n=t.options.label||{},s=m(n.onArea,!!t.area),l=s||n.connectorAllowed,h=a.boxesToAvoid,c=Number.MAX_VALUE,d=Number.MAX_VALUE,f,x,b,g,y,X,S;for(X=0;h&&X<h.length;X+=1)if(u(h[X],{left:e,right:e+r.width,top:o,bottom:o+r.height}))return!1;for(X=0;X<a.series.length;X+=1){let h=a.series[X],u=h.interpolatedPoints&&[...h.interpolatedPoints];if(h.visible&&u){let m=a.plotHeight/10;for(let t=a.plotTop;t<=a.plotTop+a.plotHeight;t+=m)u.unshift({chartX:a.plotLeft,chartY:t}),u.push({chartX:a.plotLeft+a.plotWidth,chartY:t});for(S=1;S<u.length;S+=1){if(u[S].chartX>=e-16&&u[S-1].chartX<=e+r.width+16){if(p(e,o,r.width,r.height,u[S-1].chartX,u[S-1].chartY,u[S].chartX,u[S].chartY))return!1;t===h&&!b&&i&&(b=p(e-16,o-16,r.width+32,r.height+32,u[S-1].chartX,u[S-1].chartY,u[S].chartX,u[S].chartY))}(l||b)&&(t!==h||s)&&(c=Math.min(c,(g=e+r.width/2-u[S].chartX)*g+(y=o+r.height/2-u[S].chartY)*y))}if(!s&&l&&t===h&&(i&&!b||c<Math.pow(n.connectorNeighbourDistance||1,2))){for(S=1;S<u.length;S+=1)(f=Math.min(Math.pow(e+r.width/2-u[S].chartX,2)+Math.pow(o+r.height/2-u[S].chartY,2),Math.pow(e-u[S].chartX,2)+Math.pow(o-u[S].chartY,2),Math.pow(e+r.width-u[S].chartX,2)+Math.pow(o-u[S].chartY,2),Math.pow(e+r.width-u[S].chartX,2)+Math.pow(o+r.height-u[S].chartY,2),Math.pow(e-u[S].chartX,2)+Math.pow(o+r.height-u[S].chartY,2)))<d&&(d=f,x=u[S]);b=!0}}}return(!i||!!b)&&{x:e,y:o,weight:c-(x?d:0),connectorPoint:x}}function S(t){if(this.renderer){let e=this,o=s(e.renderer.globalAnimation).duration;e.labelSeries=[],e.labelSeriesMaxSum=0,e.seriesLabelTimer&&n.clearTimeout(e.seriesLabelTimer),e.series.forEach(function(r){let i=r.options.label||{},a=r.labelBySeries,n=a&&a.closest;i.enabled&&r.visible&&(r.graph||r.area)&&!r.boosted&&e.labelSeries&&(e.labelSeries.push(r),i.minFontSize&&i.maxFontSize&&r.yData&&(r.sum=r.yData.reduce((t,e)=>(t||0)+(e||0),0),e.labelSeriesMaxSum=Math.max(e.labelSeriesMaxSum||0,r.sum||0)),"load"===t.type&&(o=Math.max(o,s(r.options.animation).duration)),n&&(void 0!==n[0].plotX?a.animate({x:n[0].plotX+n[1],y:n[0].plotY+n[2]}):a.attr({opacity:0})))}),e.seriesLabelTimer=y(function(){e.series&&e.labelSeries&&function(t){t.boxesToAvoid=[];let e=t.labelSeries||[],o=t.boxesToAvoid;t.series.forEach(t=>(t.points||[]).forEach(e=>(e.dataLabels||[]).forEach(e=>{let{width:r,height:i}=e.getBBox(),a=(e.translateX||0)+(t.xAxis?t.xAxis.pos:t.chart.plotLeft),n=(e.translateY||0)+(t.yAxis?t.yAxis.pos:t.chart.plotTop);o.push({left:a,top:n,right:a+r,bottom:n+i})}))),e.forEach(function(t){let e=t.options.label||{};t.interpolatedPoints=function(t){let e,o,r,i,a;if(!t.xAxis&&!t.yAxis)return;let n=t.points,s=[],l=t.graph||t.area,h=l&&l.element,c=t.chart.inverted,p=t.xAxis,u=t.yAxis,d=c?u.pos:p.pos,f=c?p.pos:u.pos,x=c?p.len:u.len,g=c?u.len:p.len,y=m((t.options.label||{}).onArea,!!t.area),X=u.getThreshold(t.options.threshold),S={},M=c?"chartCenterX":"chartCenterY";function w(t){let e=Math.round((t.plotX||0)/8)+","+Math.round((t.plotY||0)/8);S[e]||(S[e]=1,s.push(t))}if(t.getPointSpline&&h&&h.getPointAtLength&&!y&&n.length<(t.chart.plotSizeX||0)/16){let t=l.toD&&l.attr("d");for(l.toD&&l.attr({d:l.toD}),r=h.getTotalLength(),e=0;e<r;e+=16){let t=h.getPointAtLength(e),o=c?g-t.y:t.x,r=c?x-t.x:t.y;w({chartX:d+o,chartY:f+r,plotX:o,plotY:r})}t&&l.attr({d:t});let o=n[n.length-1].pos();w({chartX:d+(o?.[0]||0),chartY:f+(o?.[1]||0)})}else{let t;for(e=0,r=n.length;e<r;e+=1){let r=n[e],[s,l]=r.pos()||[],{plotHigh:h}=r;if(b(s)&&b(l)){let e={plotX:s,plotY:l,chartX:d+s,chartY:f+l};if(y&&(h&&(e.plotY=h,e.chartY=f+h),c?e.chartCenterX=d+g-((h||r.plotY||0)+m(r.yBottom,X))/2:e.chartCenterY=f+((h||l)+m(r.yBottom,X))/2),t&&(o=Math.max(Math.abs(e.chartX-t.chartX),Math.abs(e.chartY-t.chartY)))>16)for(a=1,i=Math.ceil(o/16);a<i;a+=1)w({chartX:t.chartX+(e.chartX-t.chartX)*(a/i),chartY:t.chartY+(e.chartY-t.chartY)*(a/i),[M]:(t[M]||0)+((e[M]||0)-(t[M]||0))*(a/i),plotX:(t.plotX||0)+(s-(t.plotX||0))*(a/i),plotY:(t.plotY||0)+(l-(t.plotY||0))*(a/i)});w(e),t=e}}}return s}(t),o.push(...e.boxesToAvoid||[])}),t.series.forEach(function(e){let o=e.options.label;if(!o||!e.xAxis&&!e.yAxis)return;let r="highcharts-color-"+m(e.colorIndex,"none"),i=!e.labelBySeries,a=o.minFontSize,n=o.maxFontSize,h=t.inverted,c=h?e.yAxis.pos:e.xAxis.pos,p=h?e.xAxis.pos:e.yAxis.pos,u=t.inverted?e.yAxis.len:e.xAxis.len,d=t.inverted?e.xAxis.len:e.yAxis.len,x=e.interpolatedPoints,b=m(o.onArea,!!e.area),g=[],y=e.xData||[],S,M,w,A,Y,L,v=e.labelBySeries,E,T,C;function P(t,e,o){let r=Math.max(c,m(T,-1/0)),i=Math.min(c+u,m(C,1/0));return t>r&&t<=i-o.width&&e>=p&&e<=p+d-o.height}function j(){v&&(e.labelBySeries=v.destroy())}if(b&&!h&&(E=[e.xAxis.toPixels(y[0]),e.xAxis.toPixels(y[y.length-1])],T=Math.min.apply(Math,E),C=Math.max.apply(Math,E)),e.visible&&!e.boosted&&x){if(!v){let i=e.name;if("string"==typeof o.format?i=l(o.format,e,t):o.formatter&&(i=o.formatter.call(e)),e.labelBySeries=v=t.renderer.label(i,0,0,"connector",0,0,o.useHTML).addClass("highcharts-series-label highcharts-series-label-"+e.index+" "+(e.options.className||"")+" "+r),!t.renderer.styledMode){let r="string"==typeof e.color?e.color:"#666666";v.css(f({color:b?t.renderer.getContrast(r):r},o.style||{})),v.attr({opacity:t.renderer.forExport?1:0,stroke:e.color,"stroke-width":1})}a&&n&&v.css({fontSize:a+(e.sum||0)/(e.chart.labelSeriesMaxSum||0)*(n-a)+"px"}),v.attr({padding:0,zIndex:3}).add()}for((S=v.getBBox()).width=Math.round(S.width),Y=x.length-1;Y>0;Y-=1)b?P(M=(x[Y].chartCenterX??x[Y].chartX)-S.width/2,w=(x[Y].chartCenterY??x[Y].chartY)-S.height/2,S)&&(L=X(e,M,w,S)):(P(M=x[Y].chartX+3,w=x[Y].chartY-S.height-3,S)&&(L=X(e,M,w,S,!0)),L&&g.push(L),P(M=x[Y].chartX+3,w=x[Y].chartY+3,S)&&(L=X(e,M,w,S,!0)),L&&g.push(L),P(M=x[Y].chartX-S.width-3,w=x[Y].chartY+3,S)&&(L=X(e,M,w,S,!0)),L&&g.push(L),P(M=x[Y].chartX-S.width-3,w=x[Y].chartY-S.height-3,S)&&(L=X(e,M,w,S,!0))),L&&g.push(L);if(o.connectorAllowed&&!g.length&&!b)for(M=c+u-S.width;M>=c;M-=16)for(w=p;w<p+d-S.height;w+=16)(A=X(e,M,w,S,!0))&&g.push(A);if(g.length){g.sort((t,e)=>e.weight-t.weight),L=g[0],(t.boxesToAvoid||[]).push({left:L.x,right:L.x+S.width,top:L.y,bottom:L.y+S.height});let o=Math.sqrt(Math.pow(Math.abs(L.x-(v.x||0)),2)+Math.pow(Math.abs(L.y-(v.y||0)),2));if(o&&e.labelBySeries){let r,a={opacity:t.renderer.forExport?1:0,x:L.x,y:L.y},n={opacity:1};o<=10&&(n={x:a.x,y:a.y},a={}),i&&(r=s(e.options.animation),r.duration*=.2),e.labelBySeries.attr(f(a,{anchorX:L.connectorPoint&&(L.connectorPoint.plotX||0)+c,anchorY:L.connectorPoint&&(L.connectorPoint.plotY||0)+p})).animate(n,r),e.options.kdNow=!0,e.buildKDTree();let l=e.searchPoint({chartX:L.x,chartY:L.y},!0);l&&(v.closest=[l,L.x-(l.plotX||0),L.y-(l.plotY||0)])}}else j()}else j()}),x(t,"afterDrawSeriesLabels")}(e)},e.renderer.forExport||!o?0:o)}}function M(t,e,o,r,i){let a=i&&i.anchorX,n=i&&i.anchorY,s,l,h=o/2;return b(a)&&b(n)&&(s=[["M",a,n]],(l=e-n)<0&&(l=-r-l),l<o&&(h=a<t+o/2?l:o-l),n>e+r?s.push(["L",t+h,e+r]):n<e?s.push(["L",t+h,e]):a<t?s.push(["L",t,e+r/2]):a>t+o&&s.push(["L",t+o,e+r/2])),s||[]}return{compose:function(t,e){g(c,"SeriesLabel")&&(d(t,"load",S),d(t,"redraw",S),e.prototype.symbols.connector=M,h({plotOptions:{series:{label:i}}}))}}}),o(e,"masters/modules/series-label.src.js",[e["Core/Globals.js"],e["Extensions/SeriesLabel/SeriesLabel.js"]],function(t,e){return e.compose(t.Chart,t.SVGRenderer),t})});