var page = require("webpage").create();
//page.open("http://slimerjs.org", function(status){
page.open("http://www.sjtu.edu.cn", function(status){
     if (status == "success") {
         console.log("The title of the page is: "+ page.title);
     }
     else {
         console.log("Sorry, the page is not loaded");
     }
     page.close();
     phantom.exit();
})
