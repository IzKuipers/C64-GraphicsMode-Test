import { Canvas, loadImage } from "canvas";
import { writeFile } from "fs/promises";

async function readImage(
  inputPath,
  outputPath = `out/${inputPath.replace(".png", "")}.bin`,
  width,
  height
) {
  const content = await loadImage(inputPath);
  const canvas = new Canvas(width, height, "image");
  const ctx = canvas.getContext("2d");
  let result = [];

  ctx.drawImage(content, 0, 0);

  for (let x = 0; x < width; x++) {
    let r = [];

    for (let y = 0; y < height; y++) {
      /** @type {[number,number,number,number]} */
      const color = [...ctx.getImageData(x, y, 1, 1).data]; // [r, g, b, a]

      r.push(color[0] === 255 ? 0 : 1);
    }

    if (r.length === 8) {
      const hexValue = Number(`0b${r.join("")}`);
      result.push(hexValue);
      const strIdx = result.length.toString().padStart(3, "0");

      if (hexValue === 255) {
        console.log(`Byte ${strIdx}: ==== ======== =====`);
      } else {
        const strHex = `0x${hexValue
          .toString(16)
          .padStart(2, "0")
          .toUpperCase()}`;
        const strBin = hexValue.toString(2).padStart(8, "0");
        const strDec = hexValue.toString().padStart(3, "0");

        console.log(`Byte ${strIdx}: ${strHex} ${strBin} (${strDec})`);
      }
    }
  }

  const buf = Buffer.from(result);

  await writeFile(outputPath, buf);
}

readImage("font2-abc-lowercase.png", "../fonts/abc2-lowercase.bin", 355, 8);
