var input = require('fs').readFileSync('/dev/stdin', 'utf8');
var lines = input.split('\n');

var media = ((lines[0] * 3.5 + lines[1] * 7.5) / 11).toFixed(5);
console.log('MEDIA = ' + media);