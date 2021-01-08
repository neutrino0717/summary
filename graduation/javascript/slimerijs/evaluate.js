var page = require('webpage').create();
page.open("http://slimerjs.org", function (status) {
    var mainTitle = page.evaluate(function () {
        console.log('message from the web page');
        return document.querySelector("h1").textContent;
    });
    console.log('First title of the page is ' + mainTitle);
    slimer.exit()
});
