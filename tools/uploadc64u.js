// @ts-check
const { default: axios } = require("axios");
const { readFile } = require("fs/promises");
const { resolve } = require("path");

const URL = "http://192.168.178.205/v1/runners:run_prg";
const PATH = resolve("./build/graphicsmode.prg");

async function Main() {
  const content = await readFile(PATH);
  const response = await axios.post(URL, new File([content], "graphicsmode.prg"));

  console.log(response);
}

Main();
