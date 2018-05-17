<?hh // strict
namespace Usox\HackUuidGen;

use function Facebook\FBExpect\expect;
use HH\Lib\Str;

final class UuidGeneratorTest extends \PHPUnit_Framework_TestCase {

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
