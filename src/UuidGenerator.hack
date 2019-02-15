#!/usr/bin/env hhvm
/*
 *  Copyright (c) 2019-present, Daniel Jakob
 *  All rights reserved.
 *
 *  This source code is licensed under the MIT license found in the
 *  LICENSE file in the root directory of this source tree.
 *
 */

namespace Usox\HackUuidGen;

use namespace HH\Lib\Str;

final class UuidGenerator implements UuidGeneratorInterface {

	const int RANDOM_BYTES = 16;

	public function generate(): string {
		$bytes = \openssl_random_pseudo_bytes(static::RANDOM_BYTES);

		$bytes[6] = \chr(
			\ord($bytes[6]) & 0x0f | 0x40
		);
		$bytes[8] = \chr(
			\ord($bytes[8]) & 0x3f | 0x80
		);

		return \vsprintf(
				'%s%s-%s-%s-%s-%s%s%s',
				Str\chunk(\bin2hex($bytes), 4)
		);
	}
}
