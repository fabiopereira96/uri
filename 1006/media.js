var input = require('fs').readFileSync('/dev/stdin', 'utf8');
var lines = input.split('\n');

var media = ((lines[0] * 2 + lines[1] * 3 + lines[2] * 5) / 10).toFixed(1);
console.log('MEDIA = ' + media);