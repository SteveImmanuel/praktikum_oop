// Nama/NIM		: Steve Andreas I / 13517039
// Tanggal 		: 4-4-19
// Topik		: Generic

public class Main {
	public static void main(String args[]){
		System.out.println("--- Section 1 ---");
		GhostPokemon g1=new GhostPokemon();
		FightingPokemon f1=new FightingPokemon();
		NormalPokemon n1=new NormalPokemon();
		Pokemon p1=new Pokemon();
		System.out.println(g1.getName());
		System.out.println(f1.getName());
		System.out.println(n1.getName());
		System.out.println(p1.getName());
		GhostPokemon g2=new GhostPokemon("Gastly");
		FightingPokemon f2=new FightingPokemon("Machop");
		NormalPokemon n2=new NormalPokemon("Rattata");
		Pokemon p2=new Pokemon("Big Boss");
		System.out.println(g2.getName());
		System.out.println(f2.getName());
		System.out.println(n2.getName());
		System.out.println(p2.getName());
		g2.displayClass();
		f2.displayClass();
		n2.displayClass();
		p2.displayClass();
		f2.setUniqueID(12);
		g2.setUniqueID("G1");
		System.out.println(g2.getUniqueID());
		System.out.println(f2.getUniqueID());
		System.out.println("--- Section 2 ---");
		g2.checkElement();
		f2.checkElement();
		n2.checkElement();
		g2.specialSkill();
		f2.displayAura();
		g2.displayAura();
		f2.specialSkill();
		System.out.println("--- Section 3 ---");
		PokemonAction<GhostPokemon> pg2=new PokemonAction<GhostPokemon>(g2);
		PokemonAction<NormalPokemon> pn2=new PokemonAction<NormalPokemon>(n2);
		pg2.displayPokemonClass();
		pn2.displayPokemonClass();
		System.out.println(g2.getName()+" vs "+n2.getName());
		for(int i=0;i<7;i++){
			pg2.attack();
			pn2.defense();
		}
		for(int i=0;i<3;i++){
			pn2.attack();
			pg2.defense();
		}
		pn2.useSkill();
		pg2.useSkill();
		pn2.run();
		System.out.println("--- Section 4 ---");
		System.out.println("New Battle Found");
		PokemonAction<Pokemon> pp2=new PokemonAction<Pokemon>(p2);
		PokemonAction<FightingPokemon> pf2=new PokemonAction<FightingPokemon>(f2);
		pf2.displayPokemonClass();
		pp2.displayPokemonClass();
		System.out.println(p2.getName()+" vs "+f2.getName());
		for(int i=0;i<4;i++){
			pf2.attack();
			pp2.defense();
		}
		for(int i=0;i<8;i++){
			pp2.attack();
			pf2.defense();
		}
		pf2.useSkill();
		pp2.useSkill();
		pf2.run();
		System.out.println("All Battle Finished");
	}
}
