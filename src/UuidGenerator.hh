<?hh // strict
namespace Usox\HackUuidGen;

final class UuidGenerator implements UuidGeneratorInterface {

	const int RANDOM_BYTES = 16;

	public function generate(): string {
		$bytes = openssl_random_pseudo_bytes(static::RANDOM_BYTES);

		$bytes[6] = chr(
			ord($bytes[6]) & 0x0f | 0x40
		);
		$bytes[8] = chr(
			ord($bytes[8]) & 0x3f | 0x80
		);

		return vsprintf(
			'%s%s-%s-%s-%s-%s%s%s',
			str_split(bin2hex($bytes), 4)
		);
	}
}
