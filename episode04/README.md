## Intro

In this chapter we discuss the same from the database’s point of view: how we can store the data that we’re given, and how we can find it again when we’re asked for it.

Consider the world’s simplest database, implemented as two Bash functions:

```bash
#!/bin/bash
db_set () {
  echo "$1,$2" >> database
}

db_get () {
  grep "^$1," database | sed -e "s/^$1,//" | tail -n 1
}
```

And it works:

```bash
$ db_set 123456 '{"name":"London","attractions":["Big Ben","London Eye"]}'
$ db_set 42 '{"name":"San Francisco","attractions":["Golden Gate Bridge"]}'

$ db_get 42
{"name":"San Francisco","attractions":["Golden Gate Bridge"]}
```

Our db_set function actually has pretty good performance for something that is so
simple, because **appending to a file is generally very efficient.**


Similarly to what ```db_set``` does, many databases internally use a log, which is an append-only data file.

>The word log is often used to refer to application logs, where an
application outputs text that describes what’s happening. In this
book, log is used in the more general sense: an append-only
sequence of records. It doesn’t have to be human-readable; it might
be binary and intended only for other programs to read.


On the other hand, our ```db_get``` function has terrible performance if you have a large
number of records in your database.

In order to efficiently find the value for a particular key in the database, we need a
different data structure: an index.

An index is an additional structure that is derived from the primary data.
- Many databases allow you to add and remove indexes, and this doesn’t affect the contents of the
database.
- it only affects the performance of queries
- Maintaining additional structures incurs overhead, especially on writes. 
    - For writes, it’s hard to beat the performance of simply appending to a file, because that’s the simplest possible write operation. 
    - Any kind of index usually slows down writes, because the index also needs to be updated every time data is written.

**This is an important trade-off in storage systems: well-chosen indexes speed up read queries, but every index slows down writes.** 