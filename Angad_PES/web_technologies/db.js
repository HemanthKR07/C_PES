var mongoCLient = require('mongodb')
var url = "mongodb://localhost:27017/class b"
function mongo(err,db){
    if(err) throw err;
    console.log("Database created");
    db.close();
}
mongo()
mongoCLient.MongoClient.connect(url)
    .then(db => {
        var dbo = db.db("class b");

        return dbo.collection("students").insertOne({ name: "Angad", age: 19 })
            .then(res => {
                console.log("angad added");

                return dbo.collection("students").findOne({});
            })
            .then(output => {
                return dbo.collection("students").insertMany(
                    [
                        { name: "A", age: 19 },
                        { name: "B", age: 20 },
                        { name: "C", age: 21 },
                        { name: "D", age: 22 },
                        { name: "E", age: 23 },
                    ]
                );
            })
            .then(result => {
                console.log(result);

                var query = { name: "Angad" };
                var newValues = { $set: { age: 23 } };
                return dbo.collection("students").updateOne(query, newValues);
            })
            .then(res => {
                console.log("angad updated");

                var query = { name: "Angad" };
                return dbo.collection("students").deleteOne(query);
            })
            .then(obj => {
                console.log("Angad deleted");
                db.close();
            });
    })
    .catch(err => {
        console.error(err);
    });