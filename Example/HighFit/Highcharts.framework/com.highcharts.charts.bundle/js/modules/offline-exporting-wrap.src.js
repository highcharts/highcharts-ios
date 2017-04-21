(function(H) {
    H.wrap(H.Chart.prototype, 'addButton', function(proceed, options) {
     
     proceed.apply(this, Array.prototype.slice.call(arguments, 1));
      var chart = this;
      
      chart.exportSVGElements[1].on('touchstart', function() {
        chart.exportChartLocal();
      });
    });
})(Highcharts);
