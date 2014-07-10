stordb
======

StorDB = LevelDB + V8 (ES6)

## status

WIP


## example

```js
module example {
  print(env.get('USER')); // jwerle
  var dba = stordb.open('/tmp/test-db-a');
  var dbb = stordb.open('/tmp/test-db-b');

  dba.put('a', '123');
  dba.put('b', '456');
  dba.put('c', '789');

  dbb.put('a', dba.get('a'));
  dbb.put('b', dba.get('b'));
  dbb.put('c', dba.get('c'));

  print('a:');
  print(dba.get('a'));
  print(dba.get('a'));
  print('');

  print('b:');
  print(dba.get('b'));
  print(dba.get('b'));
  print('');

  print('c:');
  print(dba.get('c'));
  print(dba.get('c'));
  print('');
}
```

## license

MIT
