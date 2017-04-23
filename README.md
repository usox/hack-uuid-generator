[![Build Status](https://travis-ci.org/usox/hack-uuid-generator.svg?branch=master)](https://travis-ci.org/usox/hack-uuid-generator)

Hack Uuid Generator
===================

This library creates random version 4 uuids according to RFC 4122.

Sample
------

```php
$uuid_generator = new \Usox\HackUuidGen\UuidGenerator();
$uuid = $uuid_generator->generate();
```
