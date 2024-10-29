var mongoCLient = require('mongodb')
var url = "mongodb://localhost:27017/class b"
function mongo(err,db){
    if(err) throw err;
    console.log("Database created");
    db.close();
}
mongo()