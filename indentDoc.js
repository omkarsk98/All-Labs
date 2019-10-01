const fs = require("fs");

var allLines = fs
  .readFileSync("./README.md")
  .toString()
  .split("\n");
fs.writeFileSync("./README.md", "", function() {
  // console.log("file is empty");
});
allLines.forEach(function(line) {
  var newLine = line + "  ";
  // console.log(newLine);
  fs.appendFileSync("./README.md", newLine.toString() + "\n");
});
