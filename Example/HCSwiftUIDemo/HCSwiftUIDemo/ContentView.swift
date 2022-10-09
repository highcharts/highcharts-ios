//
//  ContentView.swift
//  HCSwiftUIDemo
//
//  Created by Highsoft AS on 22/09/2022.
//

import Highcharts
import SwiftUI

struct ContentView: View {

  private var chartOptions: HIOptions {
    let options = HIOptions()
    
    let chart = HIChart()
    chart.type = "column"
    options.chart = chart
    
    let title = HITitle()
    title.text = "Demo chart in SwiftUI"
    options.title = title
    
    let series = HIColumn()
    series.data = [49.9, 71.5, 106.4, 129.2, 144, 176, 135.6, 148.5, 216.4, 194.1, 95.6, 54.4]
    options.series = [series]
    
    return options
  }

  var body: some View {
    ChartView(options: chartOptions)
  }

}

struct ContentView_Previews: PreviewProvider {

  static var previews: some View {
    ContentView()
  }

}

struct ChartView: UIViewRepresentable {

  var options: HIOptions

  func makeUIView(context: Context) -> HIChartView {
    let chart = HIChartView()
    chart.options = options
    return chart
  }

  func updateUIView(_ uiView: HIChartView, context: Context) {
    uiView.options = options
  }

}
