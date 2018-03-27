//
//  ListDataTableViewController.swift
//  HighFit
//
//  License: www.highcharts.com/license
//  Copyright © 2018 Highsoft AS. All rights reserved.
//

import UIKit

class ListDataTableViewController: UITableViewController {
    
    var dataSources: [Any]!
    
    override init(nibName nibNameOrNil: String?, bundle nibBundleOrNil: Bundle?) {
        super.init(nibName: nibNameOrNil, bundle: nibBundleOrNil)
        
        self.title = "Data"
        
        self.tabBarItem.image = UIImage(named: "ic_insert_chart_white")
        
        do {
            if let path = Bundle.main.path(forResource: "DataSources", ofType: "json"),
                let data = try? Data(contentsOf: URL(fileURLWithPath: path)),
                let json = try JSONSerialization.jsonObject(with: data) as? [Any] {
                self.dataSources = json
            }
        } catch {
            print("Error deserializing JSON: \(error)")
        }
        
        self.tableView.tableFooterView = UIView(frame: CGRect.zero)
    }
    
    required init?(coder aDecoder: NSCoder) {
        super.init(coder: aDecoder)
    }
    
    override func viewDidLoad() {
        super.viewDidLoad()
        
        // Uncomment the following line to preserve selection between presentations
        // self.clearsSelectionOnViewWillAppear = false
        
        // Uncomment the following line to display an Edit button in the navigation bar for this view controller.
        // self.navigationItem.rightBarButtonItem = self.editButtonItem()
    }
    
    override func didReceiveMemoryWarning() {
        super.didReceiveMemoryWarning()
        // Dispose of any resources that can be recreated.
    }
    
    // MARK: - Table view data source
    
    override func numberOfSections(in tableView: UITableView) -> Int {
        return 1
    }
    
    override func tableView(_ tableView: UITableView, numberOfRowsInSection section: Int) -> Int {
        return self.dataSources.count
    }
    
    
    override func tableView(_ tableView: UITableView, cellForRowAt indexPath: IndexPath) -> UITableViewCell {
        var cell: UITableViewCell? = tableView.dequeueReusableCell(withIdentifier: "HighFitCellDataType")
        
        // Configure the cell...
        if cell == nil {
            cell = UITableViewCell(style: .subtitle, reuseIdentifier: "HighFitCellDataType")
            cell!.accessoryType = .disclosureIndicator
        }
        
        let data = self.dataSources[indexPath.row] as! [String:Any]
        
        let imageName = data["icon"] as! String
        let textLabel = data["title"] as! String
        
        cell!.imageView!.image = UIImage(named: imageName)
        cell!.textLabel!.text = textLabel
        
        return cell!
    }
    
    /*
     // Override to support conditional editing of the table view.
     override func tableView(_ tableView: UITableView, canEditRowAt indexPath: IndexPath) -> Bool {
     // Return false if you do not want the specified item to be editable.
     return true
     }
     */
    
    /*
     // Override to support editing the table view.
     override func tableView(_ tableView: UITableView, commit editingStyle: UITableViewCellEditingStyle, forRowAt indexPath: IndexPath) {
     if editingStyle == .delete {
     // Delete the row from the data source
     tableView.deleteRows(at: [indexPath], with: .fade)
     } else if editingStyle == .insert {
     // Create a new instance of the appropriate class, insert it into the array, and add a new row to the table view
     }
     }
     */
    
    /*
     // Override to support rearranging the table view.
     override func tableView(_ tableView: UITableView, moveRowAt fromIndexPath: IndexPath, to: IndexPath) {
     
     }
     */
    
    /*
     // Override to support conditional rearranging of the table view.
     override func tableView(_ tableView: UITableView, canMoveRowAt indexPath: IndexPath) -> Bool {
     // Return false if you do not want the item to be re-orderable.
     return true
     }
     */
    
    //MARK: - Table View Delegate
    
    override func tableView(_ tableView: UITableView, didSelectRowAt indexPath: IndexPath) {
        // Navigation logic may go here, for example:
        // Create the next view controller.
        
        let dataView = DataTableViewController(nibName: "DataTableViewController", bundle: nil)
        
        // Pass the selected object to the new view controller.
        
        let data = self.dataSources[indexPath.row] as! [String:Any]
        
        dataView.configuration = data
        
        // Push the view controller.
        self.navigationController?.pushViewController(dataView, animated: true)
    }
    
    /*
     // MARK: - Navigation
     
     // In a storyboard-based application, you will often want to do a little preparation before navigation
     override func prepare(for segue: UIStoryboardSegue, sender: Any?) {
     // Get the new view controller using segue.destinationViewController.
     // Pass the selected object to the new view controller.
     }
     */
    
}
