//
//  HCSwiftUIDemoApp.swift
//  HCSwiftUIDemo
//
//  Created by Highsoft AS on 22/09/2022.
//

import Highcharts
import SwiftUI

@main
struct HCSwiftUIDemoApp: App {
  
    init() {
        HIChartView.preload()
    }
  
    var body: some Scene {
        WindowGroup {
            ContentView()
        }
    }
}
