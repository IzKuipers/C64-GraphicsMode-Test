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

    if (r.length) {
      const hexValue = Number(`0b${r.join("")}`);
      result.push(hexValue);
      console.log(`Byte: 0x${hexValue.toString(16).toUpperCase()}`);
    }
  }

  const buf = Buffer.from(result);

  await writeFile(outputPath, buf);
}

readImage("font2-abc-lowercase.png", "../fonts/abc2-lowercase.bin", 355, 8);
