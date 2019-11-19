let doc1 = "Ratan Tata invests in Snapdeal";
let doc2 = "Snapdeal to sell Tata Value Homes as it targets $2 billion in GMV";
let doc3 =
  "Snapdeal to sell flats with Tata Housing tie-up; Ratan Tata investment";
let doc4 = "Ratan Tata invests in online retailer Snapdeal";
let doc5 = "Ratan Tata, Tata Group's chairman emeritus, invests in Snapdeal";
let doc6 =
  "Ratan Tata Invests In Snapdeal, Joins Tech Tycoons In India's Buoyant Online Retail Space";
let doc7 =
  "Snapdeal, New Delhi-Based Online Retailer, Gets Investment From Ratan Tata";
let doc8 =
  "Tata picks up stake in Snapdeal. Ratan Tata has made a “personal investment” in the company";
let doc9 = "Ratan Tata Invests in Snapdeal, Picks Up Small Stake";
let doc10 =
  "Snapdeal partners with Tata Value Homes to sell real estate online";
let doc11 = "Ratan Tata picks up stake in Snapdeal; co aims for $2bn GMV";
let doc12 =
  "It’s official: Ratan Tata makes e-commerce foray, invests in Snapdeal";
let doc13 =
  "Mr Tata has made a personal investment in the company Snapdeal cofounder KunalBahl said";

let cor = [
  doc1,
  doc2,
  doc3,
  doc4,
  doc5,
  doc6,
  doc7,
  doc8,
  doc9,
  doc10,
  doc11,
  doc12,
  doc13
];
words = {};
// let count = 1;
// for (let i of cor) {
//   for (let j of i.split(/ |, /)) {
//     words[j.toLocaleLowerCase()] = (words[j.toLocaleLowerCase()] || "") + count;
//   }
//   count++;
// }
words = {
  ratan: "134567891112",
  tata: "123345567889101112",
  invests: "1456912",
  in: "1245668891112",
  snapdeal: "123456789101112",
  to: "2310",
  sell: "2310",
  value: "210",
  homes: "210",
  as: "2",
  it: "2",
  targets: "2",
  $2: "2",
  billion: "2",
  gmv: "211",
  flats: "3",
  with: "310",
  housing: "3",
  "tie-up": "3",
  investment: "37",
  online: "46710",
  retailer: "47",
  group: "5",
  chairman: "5",
  emeritus: "5",
  joins: "6",
  tech: "6",
  tycoons: "6",
  india: "6",
  buoyant: "6",
  retail: "6",
  space: "6",
  new: "7",
  "delhi-based": "7",
  gets: "7",
  from: "7",
  picks: "8911",
  up: "8911",
  stake: "8911",
  has: "8",
  made: "8",
  a: "8",
  personal: "8",
  investment: "8",
  the: "8",
  company: "8",
  small: "9",
  partners: "10",
  real: "10",
  estate: "10",
  co: "11",
  aims: "11",
  for: "11",
  $2bn: "11",
  "it’s": "12",
  official: "12",
  makes: "12",
  "e-commerce": "12",
  foray: "12"
};
let final = {};
Object.keys(words)
  .sort()
  .forEach(key => {
    final[key] = words[key];
  });
// console.log(final);
final = {
  $2: "2",
  $2bn: "11",
  a: "8",
  aims: "11",
  as: "2",
  billion: "2",
  buoyant: "6",
  chairman: "5",
  co: "11",
  company: "8",
  "delhi-based": "7",
  "e-commerce": "12",
  emeritus: "5",
  estate: "10",
  flats: "3",
  for: "11",
  foray: "12",
  from: "7",
  gets: "7",
  gmv: "211",
  group: "5",
  has: "8",
  homes: "210",
  housing: "3",
  in: "1245668891112",
  india: "6",
  investment: "8",
  invests: "1456912",
  it: "2",
  "it’s": "12",
  joins: "6",
  made: "8",
  makes: "12",
  new: "7",
  official: "12",
  online: "46710",
  partners: "10",
  personal: "8",
  picks: "8911",
  ratan: "134567891112",
  real: "10",
  retail: "6",
  retailer: "47",
  sell: "2310",
  small: "9",
  snapdeal: "123456789101112",
  space: "6",
  stake: "8911",
  targets: "2",
  tata: "123345567889101112",
  tech: "6",
  the: "8",
  "tie-up": "3",
  to: "2310",
  tycoons: "6",
  up: "8911",
  value: "210",
  with: "310"
};
let stops = "a	an	and	are	as	at	be	by	for	from	has	he	in	is	it	its	of	on	that	the	to	was	were	will	with".split(
  "\t"
);
// console.log(stops);
let after = {};
for (let i of Object.keys(final)) {
  if (stops.indexOf(i) === -1) {
    after[i] = final[i];
  }
}
console.log(Object.keys(final).length, Object.keys(after).length);
