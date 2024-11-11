var http = require('http')
var MongoClient = require('mongodb')

function createServer() {
    http.createServer((req, res) => {
        MongoClient.MongoClient.connect("mongodb://localhost:27017/class b")
            .then(db => {
                var dbo = db.db("class b");

                return dbo.collection("students").findOne({});
            })
            .then(output => {
                res.writeHead(200, { 'Content-Type': 'application/json' });
                res.write(JSON.stringify(output));
                res.end();
            })
            .catch(err => {
                res.writeHead(500, { 'Content-Type': 'text/plain' });
                res.write("Internal Server Error");
                res.end();
                console.error(err);
            });
    }).listen(8080);
}

createServer();
