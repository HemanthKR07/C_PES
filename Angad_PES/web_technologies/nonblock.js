var fs = require('fs');
fs.readFile('input.txt', "utf-8", (err, data)=> {
    if (err)throw err
    console.log(data);
});
var data = "This is buffers and streams";
var ws = fs.createWriteStream('output.txt');
ws.write(data, "utf-8");
ws.end();
ws.on('finish', ()=> {
    console.log("Write completed");
}
);
ws.on('error', (err)=> {
    console.log(err.stack);
}
);
console.log("Program Ended");