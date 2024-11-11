var events = require('events');
var em = new events.EventEmitter();
em.addListener('FirstEvent', function (data) {
    console.log('First subscriber: ' + data);
})
em.on('SecondEvent', function (data) {
    console.log('Second subscriber: ' + data);
})

em.emit('FirstEvent', 'This is the first event that is fired');
em.emit('SecondEvent', 'This is the second event that is fired');