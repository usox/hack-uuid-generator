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

use function Facebook\FBExpect\expect;
use HH\Lib\Str;

final class UuidGeneratorTest extends \Facebook\HackTest\HackTest {

	public function testGenerateGeneratesDifferentStrings(): void {
		$generator = new UuidGenerator();

		expect(
			$generator->generate()
		)
		->toNotBeSame(
			$generator->generate()
		);
	}

	public function testGenerateReturnsStringInExpectedFormat(): void {
		$generator = new UuidGenerator();

		$uuid = $generator->generate();

		expect(
			Str\length($uuid)
		)
		->toBeSame(36);

		expect($uuid)->toMatchRegExp('/[a-z0-9]{8}+-[a-z0-9]{4}+-[a-z0-9]{4}+-[a-z0-9]{4}+-[a-z0-9]{12}+/');
	}
}
