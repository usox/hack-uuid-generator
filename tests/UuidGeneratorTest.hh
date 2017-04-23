<?hh // strict
namespace Usox\HackUuidGen;

use HackPack\HackUnit\Contract\Assert;

final class UuidGeneratorTest {

	<<Test>>
	public function testGenerateGeneratesDifferentStrings(Assert $assert): void {
		$generator = new UuidGenerator();
		$assert->string(
			$generator->generate()
		)
		->not()
		->is($generator->generate());
	}

	<<Test>>
	public function testGenerateReturnsStringInExpectedFormat(Assert $assert): void {
		$generator = new UuidGenerator();

		$uuid = $generator->generate();

		$assert->string($uuid)->hasLength(36);

		$pattern = '/[a-z0-9]{8}+-[a-z0-9]{4}+-[a-z0-9]{4}+-[a-z0-9]{4}+-[a-z0-9]{12}+/';

		$assert->string($uuid)->matches($pattern);
	}
}
